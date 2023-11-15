/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:51:23 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:21:12 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calculate_offset(t_map *map)
{
	int		row;
	int		col;
	t_plane	offset;

	offset.x = 600;
	offset.y = 400;
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			map->pos[row][col].axis += WIDTH / 2;
			map->pos[row][col].ordi += HEIGHT / 2;
		}
	}
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || y < 0) || x > WIDTH - 2 || y > HEIGHT - 2)
		return ;
	dst = mlx->add + (y * mlx->len + x * (mlx->bit / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_mlx *mlx, t_pos curr, t_pos next)
{
	int	dx;
	int	dy;
	int	err;

	dx = abs((int)next.axis - (int)curr.axis);
	dy = abs((int)next.ordi - (int)curr.ordi);
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(mlx, (int)curr.axis, (int)curr.ordi, curr.chro);
		if ((int)curr.axis == (int)next.axis \
			&& (int)curr.ordi == (int)next.ordi) 
			break ;
		if (2 * err > -dy)
		{
			err -= dy;
			curr.axis += plot_scale(curr.axis, next.axis);
		}
		if (2 * err < dx)
		{
			err += dx;
			curr.ordi += plot_scale(curr.ordi, next.ordi);
		}
	}
}

int	plot_scale(int curr, int next)
{
	int	scale;

	if (curr < next) 
		scale = 1;
	else
		scale = -1;
	return (scale);
}

void	draw_wireframe(t_map *map)
{
	int	row;
	int	col;

	calculate_offset(map);
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			if (col < map->width - 1)
				draw_line(&map->mlx, \
					map->pos[row][col], map->pos[row][col + 1]);
			if (row < map->height - 1)
				draw_line(&map->mlx, \
					map->pos[row][col], map->pos[row + 1][col]);
		}
	}
}
