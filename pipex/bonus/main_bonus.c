/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:37:28 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/09/21 16:37:23 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char **env)
{
	t_cmd	*arr;
	t_file	file;

	if (is_here_doc(argv[1]))
	{
		file.in = open("./here_doc", O_WRONLY | O_CREAT | O_EXCL, 0644);
		file.out = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
		execute_here_doc(argc, argv, env, file);
	}
	else
	{
		file.in = open(argv[1], O_RDONLY);
		file.out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		arr = set_cmd(get_path(env), argc, argv);
		create_process(arr, file, argc - 3);
		return (0);
	}
}
