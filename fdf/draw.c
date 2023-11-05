/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:51:23 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/06 03:36:45 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_map *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(t_map *mlx, int x0, int y0, int x1, int y1, int color)
{
    // Compute the difference between the start and end points
    int dx;
    int dy;
    int sx;
    int sy;
    
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);

    // Determine the direction for x-axis movement
    if (x0 < x1) 
        sx = 1;  // Move scale * right
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

// Check if a point is inside the viewport
int is_inside_viewport(int x, int y)
{
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

void	draw_wireframe(t_map *map)
{
    int		row;
	int		col;
    t_arr2D	curr, right, below, offset;

	offset = calculate_offset(map);
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
				if (is_inside_viewport(curr.x + offset.x, curr.y + offset.y) && is_inside_viewport(right.x + offset.x, right.y + offset.y))
                	draw_line(map, curr.x + offset.x, curr.y + offset.y, right.x + offset.x, right.y + offset.y, map->pos[row][col].chroma); // Use desired color
            }
            // Draw the vertical line if not on the bottommost row
            if (row < map->height - 1)
            {
                below = map->arr[row + 1][col];
				if (is_inside_viewport(curr.x + offset.x, curr.y + offset.y) && is_inside_viewport(below.x + offset.x, below.y + offset.y))
                	draw_line(map, curr.x + offset.x, curr.y + offset.y, below.x + offset.x, below.y + offset.y, map->pos[row][col].chroma); // Use desired color
            }
			col++;
        }
		row++;
    }
}