/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_multi_pipe_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <amoderan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:42:30 by alex              #+#    #+#             */
/*   Updated: 2026/02/06 05:34:16 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pipex_multi_pipe(int argc, char *argv[], char **envp)
{
	int		waiting;
	t_datap	data;
	int		status;

	waiting = 1;
	data.here_doc = 0;
	data.fd_infile = -1;
	data.fd_outfile = -1;
	loop_pipe(&data, argv, envp, argc);
	data.pid_multi = fork();
	if (data.pid_multi < 0)
		perror("Fork failed");
	else if (data.pid_multi == 0)
		exec_child_process_out_multi(&data, argv, envp, argc);
	if (data.fd_infile >= 0)
		close(data.fd_infile);
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
		perror(argv[argc - 1]);
		exit(1);
	}
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->fd_outfile, STDOUT_FILENO);
	close(data->fd_outfile);
	close(data->fd_infile);
	execute_cmd(argv[argc - 2], envp);
}

static void	open_fd_infile(int i, t_datap *data, char **argv)
{
	if (i == 2)
	{
		data->fd_infile = open(argv[1], O_RDONLY);
		if (data->fd_infile == -1)
		{
			perror(argv[1]);
			close(data->pipe_fd[0]);
			close(data->pipe_fd[1]);
			exit(1);
		}
	}
}

void	loop_pipe(t_datap *data, char **argv, char **envp, int argc)
{
	int	i;

	i = 2;
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
			open_fd_infile(i, data, argv);
			dup2(data->fd_infile, STDIN_FILENO);
			dup2(data->pipe_fd[1], STDOUT_FILENO);
			close_pipe_multi_fork(data);
			execute_cmd(argv[i], envp);
		}
		close_pipe_multi(data);
		data->fd_infile = data->pipe_fd[0];
		i++;
	}
}

void	close_pipe_multi(t_datap *data)
{	
	if (data->fd_infile >= 0)
		close(data->fd_infile);
	if (data->pipe_fd[1] >= 0)
		close(data->pipe_fd[1]);
}
