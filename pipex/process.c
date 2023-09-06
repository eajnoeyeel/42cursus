/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:57:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/09/07 03:05:55 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int infile, int *fd)
{
	close(infile);
	infile = dup(fd[READ]);
	close(fd[READ]);
	close(fd[WRITE]);
}

void	child_process(t_cmd **cmd, int *fd, int idx)
{
	close(fd[READ]);
	close(fd[WRITE]);
	execve((*cmd)[idx].set[0], (*cmd)[idx].set, NULL);
	exit(-1);
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
			dup2(file.in, STDIN_FILENO);
			if (idx == cnt - 1)
				dup2(file.out, STDOUT_FILENO);
			else
				dup2(fd[WRITE], STDOUT_FILENO);
			child_process(&cmd, fd, idx);
		}
		else
			parent_process(file.in, fd);
		// The pid parameter specifies the set of child processes for which to wait.
		// If pid == 0, the call waits for any child process in the process group of the caller.
		// If waitpid() returns due to a stopped or terminated child process,
		// the process ID of the child is returned to the calling process.
		// Otherwise, a value of -1 is returned and errno is set to indicate the error.
	}
	while (waitpid(0, NULL, 0) >= 0)
		;
}
