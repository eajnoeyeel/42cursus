/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:37:28 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/09/21 16:34:30 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	t_cmd	*arr;
	t_file	file;

	if (argc != 5)
		return (0);
	file.in = open(argv[1], O_RDONLY);
	if (file.in < 0)
		ft_printf("%s\n", strerror(errno));
	file.out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	arr = set_cmd(get_path(env), argc, argv);
	create_process(arr, file, argc - 3);
	return (0);
}
