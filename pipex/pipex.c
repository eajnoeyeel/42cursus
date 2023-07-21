/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyeonjae <iyeonjae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:37:28 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/07/22 00:47:04 by iyeonjae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(char **env)
{
	char *res;

	while (ft_strncmp("PATH=", *env, 5))
		env++;
	res = *env + 5;
	return (res);
}

int ft_linecnt(char **str)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char    **get_cmd(char *path, char *arg, char **err)
{
	int     idx;
	char    *tmp;
	char    **cmd;
	char    **res;

	cmd = ft_split(arg, ' ');
	res = ft_split(path, ':');
	tmp = ft_strjoin("/", cmd[0]);
	free(cmd[0]);
	cmd[0] = tmp;
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

void    exe_cmd(char *path, int argc, char *argv[])
{
	int     idx;
	char    *err;
	char    **res;

	idx = 1;
	while (++idx < argc)
		res = get_cmd(path, argv[idx], &err);
	// ft_printf("%s\n%s\n", res[0], res[1]);
	execve(res[0], res, NULL);
}

int main(int argc, char *argv[], char **env)
{
	char	*res;

	res = get_path(env);
	exe_cmd(res, argc, argv);
	return (0);
}
