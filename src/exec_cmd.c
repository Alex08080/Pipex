/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:56:11 by alex              #+#    #+#             */
/*   Updated: 2026/01/21 14:58:08 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		ft_putstr_fd("Command not found\n", 2);
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
