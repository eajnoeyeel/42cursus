/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 16:05:09 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_scale(t_map *map)
{
	if (0 <= map->scale && map->scale <= 800)
		map->scale += SCALE_FACTOR;
}

void    axonometric_projection(t_map *map)
{
	int     row;
	int     col;
	t_pos   tmp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->pos[row][col];
			map->pos[row][col].x = tmp.x - tmp.y;
			map->pos[row][col].y = (tmp.x + tmp.y) / 2 - tmp.z;
			col++;
		}
		row++;
	}
}

void    isometric_projection(t_map *map)
{
	int     row;
	int     col;
	t_pos   tmp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->pos[row][col];
			map->pos[row][col].x = tmp.x - tmp.y;
			map->pos[row][col].y = (tmp.x + tmp.y) / 2 - tmp.z;
			map->pos[row][col].x *= map->scale;
			map->pos[row][col].y *= map->scale;
			col++;
		}
		row++;
	}
}