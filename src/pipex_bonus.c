/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <amoderan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:55:26 by alex              #+#    #+#             */
/*   Updated: 2026/02/06 05:40:50 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
		return (pipex(argv, envp));
	else if (argc > 5 && !ft_strncmp("here_doc", argv[1], 9))
		return (pipex_here_doc(argc, argv, envp));
	else if (argc > 5)
		return (pipex_multi_pipe(argc, argv, envp));
	return (0);
}

void	close_pipe_multi_fork(t_datap *data)
{
	if (data->fd_infile >= 0)
		close(data->fd_infile);
	if (data->pipe_fd[1] >= 0)
		close(data->pipe_fd[1]);
	if (data->pipe_fd[0] >= 0)
		close(data->pipe_fd[0]);
}

void	loop_waiting(t_datap *data)
{
	int	waiting;
	int	status;

	status = 0;
	waiting = 1;
	while (waiting > 0)
	{
		waiting = waitpid(-1, &status, 0);
		if (waiting == data->pid_multi)
			data->status = status;
	}
}
