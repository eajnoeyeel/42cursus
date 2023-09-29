/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:57:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/09/29 18:39:20 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	setup_parent_input_fd(int infile, int *fd)
{
	dup2(fd[READ], infile);
	close(fd[READ]);
	close(fd[WRITE]);
}

void	setup_child_redir(t_file file, int *fd, int idx, int cnt)
{
	if (dup2(file.in, STDIN_FILENO) == -1)
		ft_printf("%s\n", strerror(errno));
	if (idx == cnt - 1)
	{
		if (dup2(file.out, STDOUT_FILENO) == -1)
			ft_printf("%s\n", strerror(errno));
	}
	else
	{
		if (dup2(fd[WRITE], STDOUT_FILENO) == -1)
			ft_printf("%s\n", strerror(errno));
	}
}

void	exe_cmd_in_child(t_cmd **cmd, int *fd, int idx)
{
	close(fd[READ]);
	close(fd[WRITE]);
	execve((*cmd)[idx].set[0], (*cmd)[idx].set, NULL);
	ft_free(cmd, ft_linecnt(cmd));
	exit(EXIT_FAILURE);
}

void	create_process(t_cmd *cmd, t_file file, int cnt)
{
	int		fd[2];
	int		idx;
	pid_t	pid;

	idx = -1;
	while (++idx < cnt)
	{
		if (pipe(fd) < 0)
			return ;
		pid = fork();
		if (!pid)
		{
			setup_child_redir(file, fd, idx, cnt);
			exe_cmd_in_child(&cmd, fd, idx);
		}
		else
			setup_parent_input_fd(file.in, fd);
	}
	while (waitpid(0, NULL, 0) >= 0)
		;
}
