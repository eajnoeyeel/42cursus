/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:39:17 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/30 02:22:15 by yeolee2          ###   ########.fr       */
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

# define WHITE	0xFFFFFF
# define WIDTH	1000
# define HEIGHT	800

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
	//TODO: May need modification regarding the data type
	int		chroma;
}			t_pos;

typedef struct s_arr
{
	double	x;
	double	y;
}		t_arr;

typedef struct s_bound
{
    t_arr	min;
    t_arr	max;
	t_arr	fig;
}			t_bound;

typedef struct s_map
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	struct s_arr	**arr;
	struct s_pos	**pos;
}					t_map;

#endif