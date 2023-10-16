/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:47:02 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/17 00:43:41 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: Color info
void	parse_map(char **tmp, t_map *map, int row)
{
	char	**dum;
	int		len;
	int		col;

	// Because tmp has a newline at the end
	len = ft_linecnt(tmp) - 1;
	// res = malloc(sizeof(int) * len);
	col = -1;
	map->pos[row] = malloc(sizeof(t_pos) * len);
	while (++col < len)
	{
		if (ft_strrchr(tmp[col], ','))
		{
			dum = ft_split(tmp[col], ',');
			map->pos[row][col].chro = dum[1];
			// Always use ft_free when freeing the splitted object
			ft_free(dum, ft_linecnt(dum));
		}
		else
			map->pos[row][col].chro = WHITE;
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

	// TODO: Check if the file has a ".fdf" extension
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
		map->pos = malloc(sizeof(t_pos) * row);
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
		// Close the file when done
		close(fd);
	}
	else
		ft_printf("File does not have a '.fdf' extension\n");
}

void	put_pixel_to_image(t_map *mlx, int x, int y, int color)
{
	mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
}

void	my_mlx_pixel_put(t_map *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->add + (y * mlx->len + x * (mlx->bit / 8));
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

int main(int argc, char *argv[])
{
	t_map   map;

	if (argc == 2)
		read_file(argv[1], &map);
	map.ptr = mlx_init();
	map.win = mlx_new_window(map.ptr, 1000, 800, "fdf");
	map.img = mlx_new_image(map.ptr, 1920, 1080);
	
	// char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
	// The function returns a character pointer that points to the first pixel in the image.
	// You can think of this as the "starting address" of the image data in memory.
	map.add = mlx_get_data_addr(map.img, &map.bit, &map.len, &map.end);
	draw_line(&map, 0, 0, 1920, 1080, 0x00FFFFFF);
	mlx_put_image_to_window(map.ptr, map.win, map.img, 0, 0);
	mlx_loop(map.ptr);
}
