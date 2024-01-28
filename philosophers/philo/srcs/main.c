/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:57:09 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 00:42:05 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	print_status(t_philo *philo, char *status)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return (FAILURE);
	pthread_mutex_lock(&philo->shared->flag);
	if (philo->shared->status == ALIVE)
	{
		pthread_mutex_lock(&philo->shared->print);
		printf("%lld %d %s\n", (tv - philo->shared->start_time) / 1000, philo->idx + 1, status);
		pthread_mutex_unlock(&philo->shared->print);
	}
	else
	{
		pthread_mutex_unlock(&philo->shared->flag);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->shared->flag);
	return (SUCCESS);
}

void	*run_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->shared->num == 1)
	{
		print_status(philo, "has taken a fork");
		return (NULL);
	}
	if (philo->idx % 2 == 1)
		wait_philo(philo->shared->eat);
	while (1)
	{
		if (grab_fork(philo) == FAILURE)
			return (NULL);
		if (sleep_philo(philo) == FAILURE && think_philo(philo) == FAILURE)
			return (NULL);
	}
	return (NULL);
}

void	destroy_mutex(t_shared *shared)
{
	int	idx;

	idx = 0;
	while (idx < shared->num)
	{
		pthread_mutex_destroy(&shared->fork[idx]);
		idx++;
	}
	free(shared->fork);
	pthread_mutex_destroy(&shared->print);
	pthread_mutex_destroy(&shared->flag);
}

void	free_philo_and_cleanup(t_philo *philo, t_shared *shared)
{
	free(philo);
	destroy_mutex(shared);
}

int main(int argc, char *argv[])
{
	t_philo		*philo;
	t_shared	shared;

	if (argc == 5 || argc == 6)
	{
		parse_arg(argc, argv, &shared);
		if (shared.num <= 0)
			return (0);
		philo = init_philo(&shared);
		if (philo)
			init_thread(philo, &shared);
		free_philo_and_cleanup(philo, &shared);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (0);
}
