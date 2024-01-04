/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 04:56:01 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	compute_scale(t_map *map)
{
	if (map->scale < 0 || map->scale > 800)
		return ;
	map->scale += SCALE_FACTOR;
}

void	parallel_projection(t_map *map)
{
	int		row;
	int		col;
	t_pos	tmp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->pos[row][col];
			map->pos[row][col].axis = tmp.axis;
			map->pos[row][col].ordi = tmp.ordi;
			col++;
		}
		row++;
	}
}

void	isometric_projection(t_map *map)
{
	int		row;
	int		col;
	t_pos	tmp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->pos[row][col];
			map->pos[row][col].axis = (tmp.axis - tmp.ordi) * map->scale;
			map->pos[row][col].ordi = ((tmp.axis + tmp.ordi) \
				/ 2 - tmp.alti) * map->scale;
			col++;
		}
		row++;
	}
}
