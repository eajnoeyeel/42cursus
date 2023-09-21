/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 01:45:56 by yeolee2           #+#    #+#             */
/*   Updated: 2023/09/22 01:46:34 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1

typedef struct s_cmd
{
	char	**set;
}	t_cmd;

typedef struct s_file
{
	int	in;
	int	out;
}	t_file;

/* PARSE COMMAND LINE */
int		ft_linecnt(char **str);
char	**get_cmd(char *path, char *argv);
char	**parse_cmd(char **cmd, char **res);
char	*get_path(char **env);
t_cmd	*set_cmd(char *path, int argc, char *argv[]);

/* CREATE CHILD PROCESSES AND SETUP REDIRECTIONS */
void	create_process(t_cmd *cmd, t_file file, int cnt);
void	exe_cmd_in_child(t_cmd **cmd, int *fd, int idx);
void	setup_child_redir(t_file file, int *fd, int idx, int cnt);
void	setup_parent_input_fd(int infile, int *fd);

/* BONUS */
int		is_here_doc(char *argv);
void	execute_here_doc(int argc, char *argv[], char **env, t_file file);

#endif