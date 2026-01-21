/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 17:32:00 by alex              #+#    #+#             */
/*   Updated: 2026/01/21 15:29:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_datap
{
	pid_t	pid_multi;
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];
	int		fd_infile;
	int		fd_outfile;
	int		status;
}	t_datap;

/* PARSING_CMD */

char	*path_to_find(char *cmd, char **envp);
char	*join_possible_path(char *cmd, char *folder);
void	free_split(char **tab);
int		count_env(char **envp);
int		countain_a_slash(char *str);
char	*search_possible_path(char **possible_paths, char *cmd);

/* EXECUTE PIPEX */

void	execute_cmd(char *argv_cmd, char **envp);
int		pipex(char *argv[], char **envp);
void	exec_child_process_in(t_datap *data, char **argv, char **envp);
void	exec_child_process_out(t_datap *data, char **argv, char **envp);

/* PIPEX MULTI PIPE */

int		pipex_multi_pipe(int argc, char *argv[], char **envp);
void	loop_pipe(t_datap *data, char **argv, char **envp, int argc);
void	exec_child_process_out_multi(t_datap *data, char **argv,
			char **envp, int argc);
void	close_pipe_multi(t_datap *data);

#endif 