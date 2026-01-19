/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:32:00 by alex              #+#    #+#             */
/*   Updated: 2026/01/19 02:30:42 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>

/* PARSING_CMD */

char	*path_to_find(char *cmd, char **envp);
char	*join_possible_path(char *cmd, char *folder);
void	free_split(char **tab);
int		count_env(char **envp);

#endif 