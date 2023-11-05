/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:06:28 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/04 03:27:06 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map(char **tmp, t_map *map, int row)
{
	char	**dum;
	int		len;
	int		col;

	len = ft_linecnt(tmp);
	// Store the width info of the map
	map->width = len;
	col = -1;
	map->pos[row] = malloc(sizeof(t_pos) * len);
	if (!map->pos[row])
		exit(EXIT_FAILURE);
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
	char	*needle;
	char    *line;

	// TODO: Check if the file ENDS with a ".fdf" extension
	needle = ft_strnstr(file, ".fdf", ft_strlen(file));
	if (needle != NULL && *(needle + 4) == '\0')
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
			exit(EXIT_FAILURE);
		fd = open(file, O_RDONLY);
		row = 0;
		while ((line = get_next_line(fd)))
		{
			if (line[ft_strlen(line) - 2] == ' ')
				line[ft_strlen(line) - 2] = '\0';
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
	{
		perror("File does not have a '.fdf' extension\n");
		exit(0);
	}
}