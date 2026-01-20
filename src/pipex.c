/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:34:07 by alex              #+#    #+#             */
/*   Updated: 2026/01/20 03:40:39 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <fcntl.h>

int	main(int argc, char *argv[], char **envp)
{

	if (argc == 5)
	{
		return (pipex(argv, envp));
	}
	return (0);
}

void	execute_cmd(char *argv_cmd, char **envp)
{
	char	*cmd_path;
	char	**arg_cmd;

	arg_cmd = ft_split(argv_cmd, ' ');
	if (!arg_cmd)
		exit(1);
	cmd_path = path_to_find(arg_cmd[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd(arg_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_split(arg_cmd);
		exit(127);
	}
	if (execve(cmd_path, arg_cmd, envp) == -1)
	{
		perror("Coudlnt execve\n");
		free_split(arg_cmd);
		if (cmd_path)
			free(cmd_path);
		exit(1);
	}
	free_split(arg_cmd);
	free(cmd_path);
}

int	pipex(char *argv[], char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int	pipe_fd[2];
	int fd_infile;
	int	fd_outfile;
	int	status;

	if (pipe(pipe_fd) == -1)
	{
		perror("Couldn't pipe\n");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
		perror("Fork failed\n");
	else if (pid1 == 0)
	{
		fd_infile = open(argv[1], O_RDONLY);
		if (fd_infile == -1)
		{
			perror("Coudldn't open the infile");
			exit(1);
		}
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(fd_infile);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execute_cmd(argv[2], envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("Fork failed\n");
	else if (pid2 == 0)
	{
		fd_outfile = open(argv[4], O_CREAT | O_RDWR| O_TRUNC, 0644);
		if (fd_outfile == -1)
		{
			perror("Coudldn't open the infile");
			exit(1);
		}
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_outfile);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execute_cmd(argv[3], envp);
	}
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}