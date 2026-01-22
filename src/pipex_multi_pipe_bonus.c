/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_multi_pipe_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:42:30 by alex              #+#    #+#             */
/*   Updated: 2026/01/23 00:35:15 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pipex_multi_pipe(int argc, char *argv[], char **envp)
{
	int		waiting;
	t_datap	data;

	waiting = 1;
	data.fd_infile = open(argv[1], O_RDONLY);
	data.here_doc = 0;
	if (data.fd_infile == -1)
	{
		perror("Coudldn't open the infile");
		exit(1);
	}
	loop_pipe(&data, argv, envp, argc);
	data.pid_multi = fork();
	if (data.pid_multi < 0)
		perror("Fork failed\n");
	else if (data.pid_multi == 0)
		exec_child_process_out_multi(&data, argv, envp, argc);
	close(data.fd_infile);
	while (waiting > 0)
		waiting = waitpid(-1, &data.status, 0);
	return (data.status);
}

void	exec_child_process_out_multi(t_datap *data, char **argv,
			char **envp, int argc)
{
	if (data->here_doc)
		data->fd_outfile = open(argv[argc - 1], O_CREAT | O_RDWR
				| O_APPEND, 0644);
	else
		data->fd_outfile = open(argv[argc - 1], O_CREAT | O_RDWR
				| O_TRUNC, 0644);
	if (data->fd_outfile == -1)
	{
		perror("Coudldn't open the infile");
		exit(1);
	}
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->fd_outfile, STDOUT_FILENO);
	close(data->fd_outfile);
	close(data->fd_infile);
	execute_cmd(argv[argc - 2], envp);
}

void	loop_pipe(t_datap *data, char **argv, char **envp, int argc)
{
	int	i;

	i = 2;
	while (i != argc - 2)
	{
		if (pipe(data->pipe_fd) == -1)
		{
			perror("Couldn't pipe\n");
			exit(1);
		}
		data->pid_multi = fork();
		if (data->pid_multi < 0)
			perror("Fork failed\n");
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

void	close_pipe_multi(t_datap *data)
{
	close(data->fd_infile);
	close(data->pipe_fd[1]);
}
