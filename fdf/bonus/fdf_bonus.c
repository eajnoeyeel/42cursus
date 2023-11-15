/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:08 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:19:41 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_map(t_map *map)
{
	isometric_projection(map);
	draw_wireframe(map);
	mlx_put_image_to_window(map->mlx.ptr, map->mlx.win, map->mlx.img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		exit(EXIT_FAILURE);
	read_file(argv[1], &map);
	store_original_pos(&map);
	init_mlx(&map.mlx);
	init_fdf(&map);
	mlx_destroy_image(map.mlx.ptr, map.mlx.img);
	mlx_destroy_window(map.mlx.ptr, map.mlx.win);
	exit(EXIT_SUCCESS);
}
