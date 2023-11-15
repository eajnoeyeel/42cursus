/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:51:23 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 17:56:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_offset(t_map *map)
{
	int	row;
	int	col;
	t_arr2D	offset;

	offset.x = 600;
	offset.y = 400;
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			map->pos[row][col].x += WIDTH / 2;
			map->pos[row][col].y += HEIGHT / 2;
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


void draw_line(t_mlx *mlx, t_pos curr, t_pos next)
{
	int dx;
	int dy;
	int err;
	
	dx = abs((int)next.x - (int)curr.x);
	dy = abs((int)next.y - (int)curr.y);
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(mlx, (int)curr.x, (int)curr.y, curr.chroma);
		if ((int)curr.x == (int)next.x && (int)curr.y == (int)next.y) 
			break;
		if (2 * err > -dy)
		{
			err -= dy;  // Decrease the error
			curr.x += plot_scale(curr.x, next.x);   // Move in the x direction
		}
		if (2 * err < dx)
		{
			err += dx;  // Increase the error
			curr.y += plot_scale(curr.y, next.y);   // Move in the y direction
		}
	}
}

int	plot_scale(int curr, int next)
{
	int	scale;

	// Determine the direction for axis movement
	if (curr < next) 
		scale = 1;  // Move scale * right
	else
		scale = -1; // Move left
	return (scale);

}

void	draw_wireframe(t_map *map)
{
	int		row;
	int		col;
	t_pos	curr;
	t_pos	right;
	t_pos	below;

	calculate_offset(map);
	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			curr = map->pos[row][col];
			if (col < map->width - 1)
			{
				right = map->pos[row][col + 1];
				draw_line(&map->mlx, curr, right);
			}
			if (row < map->height - 1)
			{
				below = map->pos[row + 1][col];
				draw_line(&map->mlx, curr, below);
			}
		}
	}
}

void	draw_map(t_map *map)
{
	isometric_projection(map);
	draw_wireframe(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.win, map->mlx.img, 0, 0);
}
