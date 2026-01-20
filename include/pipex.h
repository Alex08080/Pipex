/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:32:00 by alex              #+#    #+#             */
/*   Updated: 2026/01/20 03:40:23 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_cmd
{
	char	*cmd_one;
	char	*cmd_two;
	char	**args_cmd_one;
	char	**args_cmd_two;
	int		fd_in;
	int		fd_out;
}	t_cmd;

/* PARSING_CMD */

char	*path_to_find(char *cmd, char **envp);
char	*join_possible_path(char *cmd, char *folder);
void	free_split(char **tab);
int		count_env(char **envp);
int		countain_a_slash(char *str);

/* EXECUTE PIPEX */

void	execute_cmd(char *argv_cmd, char **envp);
int		pipex(char *argv[], char **envp);
#endif 