/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:44:16 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:19:55 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	exit_program(t_map *map)
{
	if (map->org)
		free_original_pos(map);
	mlx_destroy_image(map->mlx.ptr, map->mlx.img);
	mlx_destroy_window(map->mlx.ptr, map->mlx.win);
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

int	handle_key(int keycode, t_map *map)
{
	double	delta;

	delta = 0.05;
	if (keycode == KEY_ESC)
		exit_program(map);
	else if (keycode == KEY_LEFT)
		map->theta.z += delta;
	else if (keycode == KEY_RIGHT)
		map->theta.z -= delta;
	else if (keycode == KEY_UP)
		map->theta.y += delta;
	else if (keycode == KEY_DOWN)
		map->theta.y -= delta;
	else if (keycode == KEY_ZOOM_IN)
		map->scale++;
	else if (keycode == KEY_ZOOM_OUT)
		map->scale--;
	apply_rotation(map);
	mlx_destroy_image(map->mlx.ptr, clean_old_image(&map->mlx));
	draw_map(map);
	return (0);
}
