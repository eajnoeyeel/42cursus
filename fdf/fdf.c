/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:45:08 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 16:50:05 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
	t_map   map;

	if (argc != 2)
		exit(EXIT_FAILURE);
	read_file(argv[1], &map);
	store_original_pos(&map);
	init_mlx(&map.mlx);
	init_fdf(&map);
}