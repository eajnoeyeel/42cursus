/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:26:49 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:19:58 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->len, &mlx->end);
}

void	init_val(t_map *map)
{
	map->scale = 10;
	map->theta.x = 0;
	map->theta.y = 0;
	map->theta.z = 0;
}

void	init_fdf(t_map *map)
{
	init_val(map);
	draw_map(map);
	mlx_hook(map->mlx.win, 2, 1L << 0, handle_key, map);
	mlx_hook(map->mlx.win, 17, 1L << 0, exit_program, map);
	mlx_loop(map->mlx.ptr);
}
