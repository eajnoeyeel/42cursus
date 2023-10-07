/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:47:02 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/08 00:26:23 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO: Color info
int	*parse_map(char **tmp)
{
	int	*res;
	int	len;
	int	col;

	len = ft_linecnt(tmp) - 1;
	res = malloc(sizeof(int) * len);
	col = 0;
	while (col < len)
	{
		res[col] = ft_atoi(tmp[col]);
		col++;
	}
	free(tmp);
	return (res);
}

void	read_file(char *file, t_pos *map)
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
		while ((line = get_next_line(fd)))
		{
			tmp = ft_split(line, ' ');
			// Inside tmp is going to be as follows
			// 1
			// 0
			// 0
			// -1
			// -1
			map->pos[row] = parse_map(tmp);
			free(line);
			row++;
		}
        // Close the file when done
        close(fd);
    }
	else
        ft_printf("File does not have a '.fdf' extension\n");
}

int main(int argc, char *argv[])
{
	t_pos   map;

	if (argc == 2)
		read_file(argv[1], &map);
	map.ptr = mlx_init();
	mlx_new_window(map.ptr, 50, 50, "fdf");
}
