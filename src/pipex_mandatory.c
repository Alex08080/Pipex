/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:44:06 by alex              #+#    #+#             */
/*   Updated: 2026/01/21 15:10:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pipex(char *argv[], char **envp)
{
	t_datap	data;

	if (pipe(data.pipe_fd) == -1)
	{
		perror("Couldn't pipe\n");
		exit(1);
	}
	data.pid1 = fork();
	if (data.pid1 < 0)
		perror("Fork failed\n");
	else if (data.pid1 == 0)
		exec_child_process_in(&data, argv, envp);
	data.pid2 = fork();
	if (data.pid2 < 0)
		perror("Fork failed\n");
	else if (data.pid2 == 0)
		exec_child_process_out(&data, argv, envp);
	close(data.pipe_fd[1]);
	close(data.pipe_fd[0]);
	waitpid(data.pid1, &data.status, 0);
	waitpid(data.pid2, &data.status, 0);
	if (WIFEXITED(data.status))
		return (WEXITSTATUS(data.status));
	return (1);
}
