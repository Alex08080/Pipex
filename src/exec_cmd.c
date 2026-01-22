/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:56:11 by alex              #+#    #+#             */
/*   Updated: 2026/01/22 17:02:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_cmd(char *argv_cmd, char **envp)
{
	char	*cmd_path;
	char	**arg_cmd;

	arg_cmd = ft_split(argv_cmd, ' ');
	if (!arg_cmd || !arg_cmd[0])
	{
		perror("Command not found");
		if (arg_cmd)
			free(arg_cmd);
		exit(127);
	}
	cmd_path = path_to_find(arg_cmd[0], envp);
	if (!cmd_path)
	{
		free_split(arg_cmd);
		exit(127);
	}
	if (execve(cmd_path, arg_cmd, envp) == -1)
	{
		perror("Coudlnt execve");
		free_split(arg_cmd);
		exit(126);
	}
	free_split(arg_cmd);
	free(cmd_path);
}
