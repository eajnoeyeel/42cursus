/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:26:49 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 16:52:15 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->len, &mlx->end);
}

void    init_val(t_map *map)
{
	map->scale = 10;
	map->theta.x = 0;
	map->theta.y = 0;
	map->theta.z = 0;
}

void    init_fdf(t_map *map)
{
	init_val(map);
	draw_map(map);
	mlx_hook(map->mlx.win, 2, 1L<<0, handle_key, map);
	mlx_hook(map->mlx.win, 17, 1L<<0, exit_program, map);
	mlx_loop(map->mlx.ptr);
}

void	store_original_pos(t_map *map)
{
	int		row;
	int		col;
	
	map->org = malloc(sizeof(t_arr3D *) * map->height);
	if (!map->org)
		exit(EXIT_FAILURE);
	row = -1;
	while (++row < map->height)
	{
		map->org[row] = malloc(sizeof(t_arr3D) * map->width);
		if (!map->org[row])
		{
			free_original_pos(map);
			exit(EXIT_FAILURE);
		}
		col = -1;
		while (++col < map->width)
		{
			map->org[row][col].x = map->pos[row][col].x;
			map->org[row][col].y = map->pos[row][col].y;
			map->org[row][col].z = map->pos[row][col].z;
		}
	}
}

void	free_original_pos(t_map *map)
{
	int row;

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