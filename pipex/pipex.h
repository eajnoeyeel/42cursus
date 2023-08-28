/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:43:40 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/08/29 03:09:16 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

#define READ 0
#define WRITE 1

typedef	struct s_cmd
{
	char	**set;
}			t_cmd;

typedef struct s_file
{
	int	in;
	int	out;
}		t_file;

int		ft_linecnt(char **str);
char	**get_cmd(char *path, char *argv);
char	**parse_cmd(char ***cmd, char **res);
char	*get_path(char **env);
void	child_process(t_cmd **cmd, int *fd, int idx);
void	create_process(t_cmd *cmd, t_file file, int cnt);
void	parent_process(int infile, int *fd);
t_cmd	*set_cmd(char *path, int argc, char *argv[]);

#endif