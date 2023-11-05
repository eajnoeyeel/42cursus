/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:47:02 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/06 03:42:53 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bound calculate_bounds(t_map *map)
{
	int		row;
	int		col;
    t_bound bounds;

    bounds.min.x = map->org[0][0].x;
    bounds.min.y = map->org[0][0].y;
	bounds.min.z = map->org[0][0].z;
    bounds.max.x = map->org[0][0].x;
    bounds.max.y = map->org[0][0].y;
	bounds.max.z = map->org[0][0].z;
	row = 0;
    while (row < map->height)
	{
		col = 0;
        while (col < map->width)
		{
            bounds.min.x = fmin(bounds.min.x, map->org[row][col].x);
            bounds.min.y = fmin(bounds.min.y, map->org[row][col].y);
			bounds.min.z = fmin(bounds.min.z, map->org[row][col].z);
            bounds.max.x = fmax(bounds.max.x, map->org[row][col].x);
            bounds.max.y = fmax(bounds.max.y, map->org[row][col].y);
			bounds.max.z = fmax(bounds.max.z, map->org[row][col].z);
			col++;
        }
		row++;
    }
	bounds.fig.x = bounds.max.x - bounds.min.x;
	bounds.fig.y = bounds.max.y - bounds.min.y;
	bounds.fig.z = bounds.max.z - bounds.min.z;
    return (bounds);
}

t_arr3D	compute_scale(t_map *map)
{
	t_arr3D scale;
	double	factor;
	
	scale.x = 0;
	scale.y = 0;
	scale.z = 0;
	factor = map->scale;
	if (scale.x < 800 || scale.y < 800 || scale.z < 800)
	{
		scale.x += factor;
		scale.y += factor;
		scale.z += factor * 0.6;
	}
    return (scale);
}

t_arr2D	calculate_offset(t_map *map)
{
	int	row;
	int	col;
	t_arr2D	offset;
	t_bound	bounds;

    bounds.min.x = map->arr[0][0].x;
    bounds.min.y = map->arr[0][0].y;
    bounds.max.x = map->arr[0][0].x;
    bounds.max.y = map->arr[0][0].y;
	row = 0;
    while (row < map->height)
	{
		col = 0;
        while (col < map->width)
		{
            bounds.min.x = fmin(bounds.min.x, map->arr[row][col].x);
            bounds.min.y = fmin(bounds.min.y, map->arr[row][col].y);
            bounds.max.x = fmax(bounds.max.x, map->arr[row][col].x);
            bounds.max.y = fmax(bounds.max.y, map->arr[row][col].y);
			col++;
        }
		row++;
    }
	bounds.fig.x = bounds.max.x - bounds.min.x;
	bounds.fig.y = bounds.max.y - bounds.min.y;
	// offset.x = ((double)WIDTH - bounds.fig.x * scale.x) / 2;
	// offset.y = ((double)HEIGHT - bounds.fig.y * scale.y) / 2;
	offset.x = (WIDTH - bounds.fig.x) / 2 - bounds.min.x;
    offset.y = (HEIGHT - bounds.fig.y) / 2 - bounds.min.y;
	return (offset);
}

void	free_2D_map(t_map *map, int row)
{
	int	idx;

	if (!map->arr)
		return ;
	idx = 0;
	while (map->arr[idx] && idx < row)
	{
		free(map->arr[idx]);
		map->arr[idx] = NULL;
		idx++;
	}
	free(map->arr);
	map->arr = NULL;
}

void	isometric_projection(t_map *map)
{
	int		row;
	int		col;
	t_arr3D	scale;
	
	scale = compute_scale(map);
	if (map->arr)
		free_2D_map(map, map->height);
	map->arr = malloc(sizeof(t_arr2D *) * map->height);
	if (!map->arr)
		exit(EXIT_FAILURE);
	row = 0;
	while (row < map->height)
	{
		map->arr[row] = malloc(sizeof(t_arr2D) * map->width);
		//TODO: Considerations on freeing the struct that has been mallocated when malloc error
		if (!map->arr[row])
		{
			free_2D_map(map, row);
			exit(EXIT_FAILURE);
		}
		col = 0;
		while (col < map->width)
		{
			// Isometric Projection
			map->arr[row][col].x = (map->pos[row][col].x - map->pos[row][col].y) * scale.x;
			map->arr[row][col].y = (map->pos[row][col].x + map->pos[row][col].y) / 2 * scale.y - map->pos[row][col].z * scale.z;
			col++;
		}
		row++;
	}
}

void	store_original_pos(t_map *map)
{
	int		row;
	int		col;
	
	map->org = malloc(sizeof(t_arr3D *) * map->height);
	if (!map->org)
		exit(EXIT_FAILURE);
	row = 0;
	while (row < map->height)
	{
		map->org[row] = malloc(sizeof(t_arr3D) * map->width);
		if (!map->org[row])
			exit(EXIT_FAILURE);
		col = 0;
		while (col < map->width)
		{
			map->org[row][col].x = map->pos[row][col].x;
			map->org[row][col].y = map->pos[row][col].y;
			map->org[row][col].z = map->pos[row][col].z;
			col++;
		}
		row++;
	}
}

t_arr3D find_center(t_map *map) 
{
    t_bound bounds = calculate_bounds(map);
    t_arr3D center;
	
    center.x = (bounds.min.x + bounds.max.x) / 2;
    center.y = (bounds.min.y + bounds.max.y) / 2;
	center.z = (bounds.min.z + bounds.max.z) / 2;
    return (center);
}

void translate_to_origin(t_map *map, t_arr3D center)
{
	int	row;
	int	col;

	row = 0;
    while (row < map->height)
	{
		col = 0;
        while (col < map->width)
		{
            map->pos[row][col].x -= center.x;
            map->pos[row][col].y -= center.y;
			map->pos[row][col].z -= center.z;
			col++;
        }
		row++;
    }
}

void translate_back(t_map *map, t_arr3D center)
{
	int	row;
	int	col;

	row = 0;
    while (row < map->height)
	{
		col = 0;
        while (col < map->width)
		{
            map->pos[row][col].x += center.x;
            map->pos[row][col].y += center.y;
			map->pos[row][col].z += center.z;
			col++;
        }
		row++;
    }
}

void	apply_all_rotations(t_map *map)
{
	t_arr3D center;

	center = find_center(map);
	translate_to_origin(map, center);
	rotate_x_axis(map);
	rotate_y_axis(map);
	rotate_z_axis(map);
	translate_back(map, center);
}

void	init_theta(t_map *map)
{
	map->scale = 10;
	map->theta.x = 0;
	map->theta.y = 0;
	map->theta.z = 0;
}

int handle_key(int keycode, t_map *map)
{
	void	*old_img;
	double	delta;

	delta = M_PI / 18;
	
    if (keycode == 53) // Escape key on macOS
        // Exit the program or do something else
        exit(0);
    // Handle other key presses as needed
	else if (keycode == 123)
		map->theta.z += delta;
	else if (keycode == 124)
		map->theta.z -= delta;
	else if (keycode == 125)
		map->theta.x += delta;
	else if (keycode == 126)
		map->theta.y += delta;
	else if (keycode == 34)
		map->scale++;
	else if (keycode == 31)
		map->scale--;
		
	apply_all_rotations(map);
	//TODO: Additional keyhook features to zoom in
	
	old_img = map->img;
	map->img = mlx_new_image(map->ptr, WIDTH, HEIGHT);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, &map->line_length, &map->endian);
	isometric_projection(map);
	draw_wireframe(map);
	mlx_put_image_to_window(map->ptr, map->win, map->img, 0, 0);
	// Destroy the old image
    mlx_destroy_image(map->ptr, old_img);
    return (0);
}

void	init_map(t_map *map, char *argv[])
{
	read_file(argv[1], map);
	map->ptr = mlx_init();
	map->win = mlx_new_window(map->ptr, WIDTH, HEIGHT, "fdf");
	map->img = mlx_new_image(map->ptr, WIDTH, HEIGHT);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel, &map->line_length, &map->endian);
	map->arr = NULL;
}

void	init_fdf(t_map *map)
{
	init_theta(map);
	store_original_pos(map);
	isometric_projection(map);
	draw_wireframe(map);
	mlx_put_image_to_window(map->ptr, map->win, map->img, 0, 0);
	mlx_key_hook(map->win, handle_key, map);
	mlx_loop(map->ptr);
}

int main(int argc, char *argv[])
{
	t_map   map;

	if (argc == 2)
		init_map(&map, argv);
	init_fdf(&map);
	mlx_destroy_image(map.ptr, map.img);
	mlx_destroy_window(map.ptr, map.win);
	return (0);
}
