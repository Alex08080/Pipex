/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:43:54 by alex              #+#    #+#             */
/*   Updated: 2026/01/23 02:27:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pipex_here_doc(int argc, char *argv[], char **envp)
{
	int		waiting;
	t_datap	data;
	int		status;

	waiting = 1;
	data.here_doc = 1;
	if (pipe(data.pipe_here_doc) == -1)
	{
		perror("Couldn't pipe");
		exit(1);
	}
	if (search_limiter_and_write_here_doc(&data, argv))
		return (1);
	close(data.pipe_here_doc[1]);
	dup2(data.pipe_here_doc[0], STDIN_FILENO);
	loop_pipe_here_doc(&data, argv, envp, argc);
	data.pid_multi = fork();
	if (data.pid_multi < 0)
		perror("Fork failed");
	else if (data.pid_multi == 0)
		exec_child_process_out_multi(&data, argv, envp, argc);
	close(data.pipe_here_doc[0]);
	while (waiting > 0)
	{
		waiting = waitpid(-1, &status, 0);
		if (waiting == data.pid_multi)
			data.status = status;
	}
	if (WIFEXITED(data.status))
		return (WEXITSTATUS(data.status));
	return (1);
}

int	search_limiter_and_write_here_doc(t_datap *data, char **argv)
{
	char	*line;

	ft_putstr_fd("heredoc> ", 1);
	data->limiter = do_limiter(argv[2]);
	if (!data->limiter)
		return (1);
	line = get_next_line(0);
	if (!line)
		return (free(data->limiter), 1);
	while (ft_strncmp(line, data->limiter, ft_strlen(data->limiter) + 1))
	{
		write(data->pipe_here_doc[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			return (free(data->limiter), 1);
	}
	free(line);
	free(data->limiter);
	return (0);
}

char	*do_limiter(char *argv)
{
	char	*limiter;

	limiter = ft_strjoin(argv, "\n");
	if (!limiter)
		return (NULL);
	return (limiter);
}

void	loop_pipe_here_doc(t_datap *data, char **argv, char **envp, int argc)
{
	int	i;

	i = 3;
	data->fd_infile = data->pipe_here_doc[0];
	while (i != argc - 2)
	{
		if (pipe(data->pipe_fd) == -1)
		{
			perror("Couldn't pipe");
			exit(1);
		}
		data->pid_multi = fork();
		if (data->pid_multi < 0)
			perror("Fork failed");
		else if (data->pid_multi == 0)
		{
			dup2(data->fd_infile, STDIN_FILENO);
			dup2(data->pipe_fd[1], STDOUT_FILENO);
			close_pipe_multi(data);
			execute_cmd(argv[i], envp);
		}
		close_pipe_multi(data);
		data->fd_infile = data->pipe_fd[0];
		i++;
	}
}
