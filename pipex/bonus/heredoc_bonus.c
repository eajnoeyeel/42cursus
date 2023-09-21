/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:35:50 by yeolee2           #+#    #+#             */
/*   Updated: 2023/09/21 16:37:34 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	is_here_doc(char *argv)
{
	if (!ft_strcmp("here_doc", argv))
		return (1);
	return (0);
}

void	execute_here_doc(int argc, char *argv[], char **env, t_file file)
{
	t_cmd	*arr;
	char	*temp;
	char	*line;

	temp = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(1, "heredoc>", 9);
		line = get_next_line(0);
		if (!line || !ft_strcmp(temp, line))
		{
			free(line);
			break ;
		}
		write(file.in, line, ft_strlen(line));
		free(line);
	}
	free(temp);
	close(file.in);
	file.in = open("./here_doc", O_RDONLY);
	unlink("./here_doc");
	arr = set_cmd(get_path(env), argc - 1, &argv[1]);
	create_process(arr, file, argc - 4);
	exit(EXIT_SUCCESS);
}