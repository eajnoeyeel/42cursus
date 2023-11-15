/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 04:06:28 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/16 02:20:00 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	parse_chroma(char **tmp, t_map *map, int row, int col)
{
	char	**dum;

	if (ft_strrchr(tmp[col], ','))
	{
		dum = ft_split(tmp[col], ',');
		map->pos[row][col].chro = (int)ft_hextol(dum[1]);
		ft_free(dum, ft_linecnt(dum));
	}
	else
		map->pos[row][col].chro = WHITE;
}

void	parse_map(char **tmp, t_map *map, int row)
{
	int		col;

	map->width = ft_linecnt(tmp);
	col = -1;
	map->pos[row] = ft_calloc(map->width, sizeof(t_pos));
	if (!map->pos[row])
		exit(EXIT_FAILURE);
	while (++col < map->width)
	{
		parse_chroma(tmp, map, row, col);
		map->pos[row][col].axis = col - map->width / 2;
		map->pos[row][col].ordi = row - map->height / 2;
		map->pos[row][col].alti = ft_atoi(tmp[col]);
	}
	ft_free(tmp, ft_linecnt(tmp));
}

int	check_file_extension_and_open(char *file)
{
	int		fd;
	char	*needle;

	needle = ft_strnstr(file, ".fdf", ft_strlen(file));
	if (!needle || *(needle + 4) != '\0')
	{
		perror("File does not have a '.fdf' extension\n");
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	count_map_height(int fd)
{
	int	row;

	row = 0;
	while (get_next_line(fd))
		row++;
	close(fd);
	return (row);
}

void	read_file(char *file, t_map *map)
{
	int		fd;
	int		row;
	char	*line;

	fd = check_file_extension_and_open(file);
	map->height = count_map_height(fd);
	map->pos = ft_calloc(map->height, sizeof(t_pos *));
	if (!map->pos)
		exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	row = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 2] == ' ')
			line[ft_strlen(line) - 2] = '\0';
		parse_map(ft_split(line, ' '), map, row);
		free(line);
		row++;
	}
	close(fd);
}
