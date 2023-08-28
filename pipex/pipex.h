/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:43:40 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/08/28 17:00:33 by yeolee2          ###   ########seoul.kr  */
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

void	parent_process(int infile, int *fd);
void	create_process(t_cmd *cmd, t_file file, int cnt);

#endif