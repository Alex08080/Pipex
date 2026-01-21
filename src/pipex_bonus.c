/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:55:26 by alex              #+#    #+#             */
/*   Updated: 2026/01/21 15:28:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	if (argc == 5)
		return (pipex(argv, envp));
	else if (argc >= 5)
		return (pipex_multi_pipe(argc, argv, envp));
	return (0);
}
