/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:34:07 by alex              #+#    #+#             */
/*   Updated: 2026/01/19 15:42:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <fcntl.h>

int	main(int argc, char *argv[], char **envp)
{
	(void) argc;
	(void) argv;
	__pid_t	child_pid;
	int		status;
	(void) child_pid;
	(void) status;

	child_pid = fork();
	if (child_pid < 0)
		perror("Fork failed");
	else if (child_pid == 0)
	{
		int fd = open("test_out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			perror("Open failed");
		char *path_echo = path_to_find("echo", envp);
		if (!path_echo)
		{
			write(2, "Path not found\n", 15);
			exit(127);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		char *args[] = {"echo", "CA MARRZCHE !", NULL};
		if (execve(path_echo, args, envp) == -1)
		{
			perror("Coudl not execve");
			exit(1);
		}
	}
	else
	{
		// printf("Child process ID %d\n", child_pid);
		waitpid(child_pid, &status, 0);
		printf("Parent: Enfant terminé avec le status %d\n", status);
		// printf("Status : %d\n", status);
	}
	return (0);
}