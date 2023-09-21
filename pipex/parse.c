/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:32:12 by yeolee2           #+#    #+#             */
/*   Updated: 2023/09/21 16:33:18 by yeolee2          ###   ########.fr       */
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
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	**parse_cmd(char **cmd, char **res)
{
	int		idx;
	char	*tmp;

	idx = -1;
	while (res[++idx])
	{
		tmp = ft_strjoin(res[idx], cmd[0]);
		if (!access(tmp, F_OK))
		{
			free(cmd[0]);
			cmd[0] = tmp;
			ft_free(res, ft_linecnt(res));
			return (cmd);
		}
		else
			free(tmp);
	}
	return (NULL);
}

char	**get_cmd(char *path, char *argv)
{
	char	*tmp;
	char	**cmd;
	char	**res;

	cmd = ft_split(argv, ' ');
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
	{
		if (!access(cmd[0], F_OK))
			return (NULL);
	}
	res = ft_split(path, ':');
	tmp = ft_strjoin("/", cmd[0]);
	free(cmd[0]);
	cmd[0] = tmp;
	return (parse_cmd(cmd, res));
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