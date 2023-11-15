/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:07:16 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:20:09 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	store_original_pos(t_map *map)
{
	int	row;
	int	col;

	map->org = malloc(sizeof(t_space *) * map->height);
	if (!map->org)
		exit(EXIT_FAILURE);
	row = -1;
	while (++row < map->height)
	{
		map->org[row] = malloc(sizeof(t_space) * map->width);
		if (!map->org[row])
		{
			free_original_pos(map);
			exit(EXIT_FAILURE);
		}
		col = -1;
		while (++col < map->width)
		{
			map->org[row][col].x = map->pos[row][col].axis;
			map->org[row][col].y = map->pos[row][col].ordi;
			map->org[row][col].z = map->pos[row][col].alti;
		}
	}
}

void	free_original_pos(t_map *map)
{
	int	row;

	if (map->org != NULL)
	{
		row = 0;
		while (row < map->height)
		{
			if (map->org[row] != NULL)
			{
				free(map->org[row]);
				map->org[row] = NULL;
			}
			row++;
		}
		free(map->org);
		map->org = NULL;
	}
}

void	apply_rotation(t_map *map)
{
	int		row;
	int		col;
	t_space	tmp;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			tmp = map->org[row][col];
			map->pos[row][col].alti = tmp.z * cos(map->theta.y) \
				- tmp.x * sin(map->theta.y);
			map->pos[row][col].axis = tmp.z * sin(map->theta.y) \
				+ tmp.x * cos(map->theta.y);
			tmp.x = map->pos[row][col].axis;
			map->pos[row][col].axis = tmp.x * cos(map->theta.z) \
				- tmp.y * sin(map->theta.z);
			map->pos[row][col].ordi = tmp.x * sin(map->theta.z) \
				+ tmp.y * cos(map->theta.z);
			col++;
		}
		row++;
	}
}
