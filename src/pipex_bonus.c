/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:55:26 by alex              #+#    #+#             */
/*   Updated: 2026/01/22 20:51:21 by alex             ###   ########.fr       */
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
