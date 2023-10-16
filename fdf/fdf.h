/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:39:17 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/16 00:02:41 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

# define WHITE "0xFFFFFF"

typedef struct s_pos
{
	int				x;
	int				y;
	int				z;
	//TODO: May need modification regarding the data type
	char			*chro;
}					t_pos;

typedef struct s_map
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*add;
	int				bit;
	int				len;
	int				end;
	int				**arr;
	struct s_pos	**pos;
}					t_map;

#endif