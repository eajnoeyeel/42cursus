/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:37:28 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/08/22 05:28:28 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*res;
	
	while (ft_strncmp("PATH=", *env, 5))
		env++;
	res = *env + 5;
	return (res);
}

int	ft_linecnt(char **str)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	**parse_cmd(char ***cmd, char **res)
{
	// res[0] = /Users/yeolee2/.brew/bin
	// res[1] = /Users/yeolee2/.brew/bin
	// res[2] = /Users/yeolee2/.local/bin
	// res[3] = /usr/local/bin
	// res[4] = /usr/bin
	// ...
	int		idx;
	char	*tmp;

	idx = -1;
	while (res[++idx])
	{
		tmp = ft_strjoin(res[idx], *cmd[0]);
		// Search for the execution file among environment paths
		// tmp[0] = /Users/yeolee2/.brew/bin/ls
		// tmp[1] = /Users/yeolee2/.brew/bin/ls
		// tmp[2] = /Users/yeolee2/.local/bin/ls
		// tmp[3] = /usr/local/bin/ls
		// tmp[4] = /usr/bin/ls
		// ...
		if (!access(tmp, F_OK))
		{
			// Return the path once it's found
			// No need to search all the way
			free(*cmd[0]);
			*cmd[0] = tmp;
			ft_free(res, ft_linecnt(res));
			return (*cmd);
		}
		else
			// If not, free tmp which has been allocated at the beginning
			free(tmp);
	}
	return (NULL);
}

// ls -al
char	**get_cmd(char *path, char *argv)
{
	char	*tmp;
	char	**cmd;
	char	**res;

	// cmd[0] = "ls"
	// cmd[1] = "-al"
	cmd = ft_split(argv, ' ');
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
	{
		if (!access(cmd[0], F_OK))
			return (NULL);
	}
	res = ft_split(path, ':');
	// res[0] = /Users/yeolee2/.brew/bin
	// res[1] = /Users/yeolee2/.brew/bin
	// res[2] = /Users/yeolee2/.local/bin
	// res[3] = /usr/local/bin
	// res[4] = /usr/bin
	// ...
	tmp = ft_strjoin("/", cmd[0]);
	// tmp = "/ls"
	free(cmd[0]);
	cmd[0] = tmp;
	return (parse_cmd(&cmd, res));
}

t_cmd	*set_cmd(char *path, int argc, char *argv[])
{
	int		idx;
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd) * (argc - 3));
	idx = 1;
	while (++idx < argc - 1)
		cmd[idx - 2].set = get_cmd(path, argv[idx]);
	return (cmd);
}

int	main(int argc, char *argv[], char **env)
{
	t_cmd	*arr;
	t_file	file;

	file.in = open(argv[1], O_RDONLY);
	file.out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	arr = set_cmd(get_path(env), argc, argv);
	// for (size_t i = 0; i < argc - 3; i++)
	// 	for (size_t j = 0; arr[i].set[j]; j++)
	// 		ft_printf("arr[%d].set[idx] = %s\n", i, arr[i].set[j]);

	// TODO: infile and outfile needs to be duplicated
	create_process(arr, file, argc - 3);
	return (0);
}