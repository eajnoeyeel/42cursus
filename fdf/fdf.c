/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:47:02 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/30 02:32:24 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

// TODO: Color info
void	parse_map(char **tmp, t_map *map, int row)
{
	char	**dum;
	// TODO: Variable len might not be necessary since the width data is stored in struct
	int		len;
	int		col;

	// TODO: Because tmp has a newline at the end
	len = ft_linecnt(tmp) - 1;
	// Store the width info of the map
	map->width = len;
	col = -1;
	map->pos[row] = malloc(sizeof(t_pos) * len);
	if (!map->pos[row])
		return ;
	while (++col < len)
	{
		if (ft_strrchr(tmp[col], ','))
		{
			dum = ft_split(tmp[col], ',');
			map->pos[row][col].chroma = (int)ft_hextol(dum[1]);
			// Always use ft_free when freeing the splitted object
			ft_free(dum, ft_linecnt(dum));
		}
		else
			map->pos[row][col].chroma = WHITE;
		// Assign necessary data for each point
		map->pos[row][col].x = col;
		map->pos[row][col].y = row;
		map->pos[row][col].z = ft_atoi(tmp[col]);
	}
	ft_free(tmp, ft_linecnt(tmp));
}

void	read_file(char *file, t_map *map)
{
	int     fd;
	int		row;
	char	**tmp;
	char    *line;

	// TODO: Check if the file ENDS with a ".fdf" extension
	if (ft_strnstr(file, ".fdf", ft_strlen(file)) != NULL)
	{
		// Open the file
		fd = open(file, O_RDONLY);
		// Check if the file was successfully opened
		if (fd == -1)
		{
			ft_printf("%s\n", strerror(errno));
			return ;
		}
		// Perform necessary operations on the file as needed
		row = 0;
		while (get_next_line(fd))
			row++;
		close(fd);
		// Count rows of the map to malloc
		map->pos = malloc(sizeof(t_pos *) * row);
		if (!map->pos)
			return ;
		fd = open(file, O_RDONLY);
		row = 0;
		while ((line = get_next_line(fd)))
		{
			tmp = ft_split(line, ' ');
			// Inside tmp is going to be as follows
			// 1
			// 0
			// 0
			// -1
			// -1
			// map->arr[row] = parse_map(tmp, map, row);
			parse_map(tmp, map, row);
			free(line);
			row++;
		}
		// Store the height info of the map
		map->height = row;
		// Close the file when done
		close(fd);
	}
	else
		ft_printf("File does not have a '.fdf' extension\n");
}

// void	put_pixel_to_image(t_map *mlx, int x, int y, int color)
// {
// 	mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
// }

void	my_mlx_pixel_put(t_map *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//TODO: Parameter 'color' may not be necessary here since the t_map holds chroma
void draw_line(t_map *mlx, int x0, int y0, int x1, int y1, int color)
{
	// printf("x0 : %d, y0 : %d, x1 : %d, y1 : %d\n", x0,y0,x1,y1);
    // Compute the difference between the start and end points
    int dx;
    int dy;
    int sx;
    int sy;
    
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);

    // Determine the direction for x-axis movement
    if (x0 < x1) 
        sx = 1;  // Move right
    else
        sx = -1; // Move left

    // Determine the direction for y-axis movement
    if (y0 < y1) 
        sy = 1;  // Move down
    else 
        sy = -1; // Move up

    // Initialize the error term. 
    // It's doubled the actual error to avoid floating point operations.
    int err = dx - dy;
    int e2;

    // Loop to draw the line
    while (1)
    {
        // Plot the current point
		my_mlx_pixel_put(mlx, x0, y0, color);
		// If we've reached the end point, break out of the loop
        if (x0 == x1 && y0 == y1) 
            break;
        // Calculate double the error
        e2 = 2 * err;
        // Adjust x0 and the error term if needed
        if (e2 > -dy)
        {
            err -= dy;  // Decrease the error
            x0 += sx;   // Move in the x direction
        }
        // Adjust y0 and the error term if needed
        if (e2 < dx)
        {
            err += dx;  // Increase the error
            y0 += sy;   // Move in the y direction
        }
    }
}

t_bound calculate_bounds(t_map *map)
{
	int		row;
	int		col;
    t_bound bounds;

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
    return (bounds);
}

double	compute_scale(t_bound bounds)
{
	double	scaleX;
	double	scaleY;
	double	factor;

	factor = 0.3;
	scaleX = (double) (WIDTH * factor) / bounds.fig.x;
	scaleY = (double) (HEIGHT * factor) / bounds.fig.y;
	return (fmin(scaleX, scaleY));
}

t_arr	calculate_offset(t_bound bounds)
{
	t_arr	offset;

	offset.x = (WIDTH - bounds.fig.x) / 2;
	offset.y = (HEIGHT - bounds.fig.y) / 2;
	return (offset);
}

void	isometric_projection(t_map *map)
{
	int		row;
	int		col;
	//TODO: Implement rotation feature when key is pressed
	double	theta = M_PI / 6; // 45 degrees for isometric
	// double phi = M_PI / 6;   // 30 degrees for isometric

	// scale = 20;
	map->arr = malloc(sizeof(t_arr *) * map->height);
	row = 0;
	while (row < map->height)
	{
		map->arr[row] = malloc(sizeof(t_arr) * map->width);
		col = 0;
		while (col < map->width)
		{
			// Isometric Projection
			map->arr[row][col].x = (map->pos[row][col].x - map->pos[row][col].y) * cos(theta);
			map->arr[row][col].y = ((map->pos[row][col].x + map->pos[row][col].y) * sin(theta) - map->pos[row][col].z);
			col++;
		}
		row++;
	}
}

void	draw_wireframe(t_map *map)
{
    int		row;
	int		col;
	double	scale;
	t_bound bounds;
    t_arr	curr, right, below, offset;

	bounds = calculate_bounds(map);
	offset = calculate_offset(bounds);
	scale = compute_scale(bounds);
	row = 0;
    while (row < map->height)
    {
		col = 0;
		while (col < map->width)
        {
            curr = map->arr[row][col];
            // Draw the horizontal line if not on the rightmost edge
            if (col < map->width - 1)
            {
                right = map->arr[row][col + 1];
                draw_line(map, scale * curr.x + offset.x, scale * curr.y + offset.y, scale * right.x + offset.x, scale * right.y + offset.y, map->pos[row][col].chroma); // Use desired color
            }
            // Draw the vertical line if not on the bottommost row
            if (row < map->height - 1)
            {
                below = map->arr[row + 1][col];
                draw_line(map, scale * curr.x + offset.x, scale * curr.y + offset.y, scale * below.x + offset.x, scale * below.y + offset.y, map->pos[row][col].chroma); // Use desired color
            }
			col++;
        }
		row++;
    }
}

int main(int argc, char *argv[])
{
	t_map   map;

	if (argc == 2)
		read_file(argv[1], &map);
	map.ptr = mlx_init();
	map.win = mlx_new_window(map.ptr, WIDTH, HEIGHT, "fdf");
	map.img = mlx_new_image(map.ptr, WIDTH, HEIGHT);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, &map.line_length, &map.endian);
	isometric_projection(&map);
	draw_wireframe(&map);
	mlx_put_image_to_window(map.ptr, map.win, map.img, 0, 0);
	mlx_loop(map.ptr);
}
