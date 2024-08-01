/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:01:06 by yeolee2           #+#    #+#             */
/*   Updated: 2024/08/01 22:03:46 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	parse_arg(int argc, char *argv[], t_shared *shared)
{
	shared->num = ft_atoi(argv[1]);
	shared->die = ft_atoi(argv[2]) * 1000;
	shared->eat = ft_atoi(argv[3]) * 1000;
	shared->sleep = ft_atoi(argv[4]) * 1000;
	shared->status = ALIVE;
	if (argc == 6)
		shared->must_eat = ft_atoi(argv[5]);
	else
		shared->must_eat = -1;
	shared->eat_count = 0;
}

void	cleanup_process(t_shared *shared)
{
	int	idx;
	int	cnt;
	int	status;

	idx = 0;
	cnt = 0;
	status = 0;
	while (wait(&status) != -1)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			while (idx < shared->num)
			{
				kill(shared->pids[idx], SIGINT);
				idx++;
			}
			sem_post(shared->print);
		}
		else
			cnt++;
	}
	if (cnt == shared->num)
		printf("All philosophers have eaten %d number of times\n", \
			shared->must_eat);
}

void	init_process(t_philo *philo, t_shared *shared)
{
	int			idx;
	int			pid;
	long long	tv;

	shared->pids = malloc(sizeof(pid_t) * shared->num);
	tv = get_curr_time();
	if (tv == FAILURE)
		return ;
	shared->start_time = tv;
	idx = 0;
	while (idx < shared->num)
	{
		tv = get_curr_time();
		if (tv == FAILURE) 
			return ;
		philo[idx].last_eat = tv;
		pid = fork();
		if (pid == FAILURE)
			exit(EXIT_FAILURE);
		else if (!pid)
			run_philo(&philo[idx]);
		shared->pids[idx] = pid;
		idx++;
	}
	cleanup_process(shared);
}

int	open_semaphore(t_shared *shared)
{
	sem_unlink("fork");
	sem_unlink("print");
	shared->fork = sem_open("fork", O_CREAT, 0644, shared->num);
	if (shared->fork == SEM_FAILED)
		exit(EXIT_FAILURE);
	shared->print = sem_open("print", O_CREAT, 0644, 1);
	if (shared->print == SEM_FAILED)
		exit(EXIT_FAILURE);
	return (SUCCESS);
}

t_philo	*init_philo(t_shared *shared)
{
	int		idx;
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * shared->num);
	if (!philo)
		return (NULL);
	idx = 0;
	while (idx < shared->num)
	{
		philo[idx].idx = idx;
		philo[idx].eat_count = 0;
		philo[idx].last_eat = 0;
		philo[idx].shared = shared;
		idx++;
	}
	if (open_semaphore(shared) == SUCCESS)
		return (philo);
	return (NULL);
}
