/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:44:16 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 16:55:30 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int exit_program(t_map *map)
{
	if (map->org)
		free_original_pos(map);
	exit(EXIT_SUCCESS);
}

void	*clean_old_image(t_mlx *mlx)
{
	void	*old_img;

	old_img = mlx->img;
	mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->add = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->len, &mlx->end);
	return (old_img);
}

int		handle_key(int keycode, t_map *map)
{
	double	delta;

	delta = 0.05;
	if (keycode == KEY_ESC)
        exit_program(map);
	else if (keycode == KEY_LEFT)
		map->theta.z += delta;
	else if (keycode == KEY_RIGHT)
		map->theta.z -= delta;
	else if (keycode == KEY_DOWN)
		map->theta.y += delta;
	else if (keycode == KEY_UP)
		map->theta.x += delta;
	else if (keycode == KEY_ALPHA_I)
		map->scale++;
	else if (keycode == KEY_ALPHA_O)
		map->scale--;
	apply_rotation(map);
	mlx_destroy_image(map->mlx.ptr, clean_old_image(&map->mlx));
	draw_map(map);
	return (0);
}