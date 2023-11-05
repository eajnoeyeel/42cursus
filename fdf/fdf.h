/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:39:17 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/06 03:44:32 by yeolee2          ###   ########.fr       */
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
# define WIDTH	1200
# define HEIGHT	900

typedef struct s_pos
{
	double	x;
	double	y;
	double	z;
	//TODO: May need modification regarding the data type
	int		chroma;
}			t_pos;

typedef struct s_arr2D
{
	double	x;
	double	y;
}		t_arr2D;

typedef struct s_arr3D
{
	double	x;
	double	y;
	double	z;
}			t_arr3D;

// typedef struct s_org
// {
// 	double	x;
// 	double	y;
// 	double	z;
// }		t_org;

typedef struct s_bound
{
    t_arr3D	min;
    t_arr3D	max;
	t_arr3D	fig;
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
	struct s_pos	**pos;
	struct s_arr2D	**arr;
	struct s_arr3D	theta;
	double			scale;
	struct s_arr3D	**org;
}					t_map;

void	read_file(char *file, t_map *map);
void	parse_map(char **tmp, t_map *map, int row);
void	my_mlx_pixel_put(t_map *mlx, int x, int y, int color);
void	draw_line(t_map *mlx, int x0, int y0, int x1, int y1, int color);
t_bound calculate_bounds(t_map *map);
t_arr3D	compute_scale(t_map *map);
t_arr2D	calculate_offset(t_map *map);
void	rotate_x_axis(t_map *map);
void	rotate_y_axis(t_map *map);
void	rotate_z_axis(t_map *map);
void	isometric_projection(t_map *map);
void	draw_wireframe(t_map *map);
void	store_original_pos(t_map *map);
void	apply_all_rotations(t_map *map);
void	init_theta(t_map *map);
int handle_key(int keycode, t_map *map);
int is_inside_viewport(int x, int y);
void	init_map(t_map *map, char *argv[]);
void	init_fdf(t_map *map);

#endif