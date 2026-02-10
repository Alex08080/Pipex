/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoderan <amoderan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:56:11 by alex              #+#    #+#             */
/*   Updated: 2026/02/06 05:23:10 by amoderan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	arg_cmd_null(char ***arg_cmd)
{	
	perror("Command not found");
	if (*arg_cmd)
		free_split(*arg_cmd);
	exit(127);
}

void	execute_cmd(char *argv_cmd, char **envp)
{
	char	*cmd_path;
	char	**arg_cmd;

	arg_cmd = ft_split(argv_cmd, ' ');
	if (!arg_cmd || !arg_cmd[0])
		arg_cmd_null(&arg_cmd);
	cmd_path = path_to_find(arg_cmd[0], envp);
	if (!cmd_path)
	{
		free_split(arg_cmd);
		exit(127);
	}
	if (execve(cmd_path, arg_cmd, envp) == -1)
	{
		perror("Couldnt execve");
		free_split(arg_cmd);
		free(cmd_path);
		exit(126);
	}
	free_split(arg_cmd);
	free(cmd_path);
}
