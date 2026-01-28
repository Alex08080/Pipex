/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:48:09 by alex              #+#    #+#             */
/*   Updated: 2026/01/23 00:03:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_child_process_in(t_datap *data, char **argv, char **envp)
{
	data->fd_infile = open(argv[1], O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror(argv[1]);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		exit(1);
	}
	dup2(data->fd_infile, STDIN_FILENO);
	dup2(data->pipe_fd[1], STDOUT_FILENO);
	close(data->fd_infile);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	execute_cmd(argv[2], envp);
}

void	exec_child_process_out(t_datap *data, char **argv, char **envp)
{
	data->fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->fd_outfile == -1)
	{
		perror(argv[4]);
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		exit(1);
	}
	dup2(data->pipe_fd[0], STDIN_FILENO);
	dup2(data->fd_outfile, STDOUT_FILENO);
	close(data->fd_outfile);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	execute_cmd(argv[3], envp);
}
