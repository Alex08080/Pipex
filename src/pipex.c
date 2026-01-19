/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:34:07 by alex              #+#    #+#             */
/*   Updated: 2026/01/19 02:25:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_split(char **tab)
{
	int	i;
	
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*join_possible_path(char *cmd, char *folder)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(folder, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	if (!path)
		return (free(tmp), NULL);
	free(tmp);
	return (path);
}

int	count_env(char **envp)
{
	int	i;

	i = 0;
	if(!envp)
		return (0);
	while(envp[i])
		i++;
	return (i);
}

char	*path_to_find(char *cmd, char **envp)
{
	char	**possible_paths;
	char	*possible_path;
	int		i;
	int		nb_env;

	i = 0;
	nb_env = count_env(envp);
	if (contain_a_slash(cmd))
	{
		if(!access(cmd, F_OK | X_OK))
			return (ft_strdup(cmd));
		return (NULL);
	}
	while(envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (i == nb_env)
		return (NULL);
	possible_paths = ft_split(envp[i] + 5, ':');
	if (!possible_paths)
		return (NULL);
	i = 0;
	while(possible_paths[i])
	{
		possible_path = join_possible_path(cmd, possible_paths[i]);
		if (!possible_path)
			return (free_split(possible_paths), NULL);
		if (!access(possible_path, F_OK | X_OK))
			return(free_split(possible_paths), possible_path);
		free(possible_path);
	}
	free_split(possible_paths);
	return (NULL);
}

int	main(int argc, char *argv[], char **envp)
{
	(void) argc;
	(void) argv;
	int i = 0;
	
	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}