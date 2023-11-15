/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:50:52 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:39:47 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>

# define WHITE          0xFFFFFF
# define WIDTH          1200
# define HEIGHT         800
# define SCALE_FACTOR   1
# define KEY_ESC        53
# define KEY_LEFT       123
# define KEY_RIGHT      124
# define KEY_UP         125
# define KEY_DOWN       126
# define KEY_ZOOM_IN    34
# define KEY_ZOOM_OUT   31
# define KEY_PARALLEL	

typedef struct s_pos
{
	double	axis;
	double	ordi;
	double	alti;
	int		chro;
}			t_pos;

typedef struct s_plane
{
	double	x;
	double	y;
}			t_plane;

typedef struct s_space
{
	double	x;
	double	y;
	double	z;
}			t_space;

typedef struct s_bound
{
	t_space	min;
	t_space	max;
	t_space	fig;
}			t_bound;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*add;
	int		bit;
	int		end;
	int		len;
}			t_mlx;

typedef struct s_map
{
	int				width;
	int				height;
	double			scale;
	t_space			theta;
	struct s_mlx	mlx;
	struct s_pos	**pos;
	struct s_space	**org;
}					t_map;

void	calculate_offset(t_map *map);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_line(t_mlx *mlx, t_pos curr, t_pos next);
int		plot_scale(int curr, int next);
void	draw_wireframe(t_map *map);
void	draw_map(t_map *map);
int		exit_program(t_map *map);
void	*clean_old_image(t_mlx *mlx);
int		handle_key(int keycode, t_map *map);
void	init_mlx(t_mlx *mlx);
void	init_val(t_map *map);
void	init_fdf(t_map *map);
void	store_original_pos(t_map *map);
void	free_original_pos(t_map *map);
void	parse_chroma(char **tmp, t_map *map, int row, int col);
void	parse_map(char **tmp, t_map *map, int row);
int		check_file_extension_and_open(char *file);
int		count_map_height(int fd);
void	read_file(char *file, t_map *map);
void	compute_scale(t_map *map);
void	axonometric_projection(t_map *map);
void	isometric_projection(t_map *map);
void	rotate_x_axis(t_map *map);
void	rotate_y_axis(t_map *map);
void	rotate_z_axis(t_map *map);
void	apply_rotation(t_map *map);

#endif