/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:07:16 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 16:39:05 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_axis(t_map *map)
{
	int		row;
	int		col;
	t_arr3D	tmp;
	
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->org[row][col];
			map->pos[row][col].y = tmp.y * cos(map->theta.x) - tmp.z * sin(map->theta.x);
			map->pos[row][col].z = tmp.y * sin(map->theta.x) + tmp.z * cos(map->theta.x);
			col++;
		}
		row++;
	}
}

void	rotate_y_axis(t_map *map)
{
	int		row;
	int		col;
	t_arr3D	tmp;
	
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->org[row][col];
			map->pos[row][col].z = tmp.z * cos(map->theta.y) - tmp.x * sin(map->theta.y);
			map->pos[row][col].x = tmp.z * sin(map->theta.y) + tmp.x * cos(map->theta.y);
			col++;
		}
		row++;
	}
}

void	rotate_z_axis(t_map *map)
{
	int		row;
	int		col;
	t_arr3D	tmp;
	
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->org[row][col];
			map->pos[row][col].x = tmp.x * cos(map->theta.z) - tmp.y * sin(map->theta.z);
			map->pos[row][col].y = tmp.x * sin(map->theta.z) + tmp.y * cos(map->theta.z);
			col++;
		}
		row++;
	}
}

void	apply_rotation(t_map *map)
{
	// rotate_x_axis(map);
	// rotate_y_axis(map);
	rotate_z_axis(map);
}