/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:01:06 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 01:34:56 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	parse_arg(int argc, char *argv[], t_shared *shared)
{
	shared->num = atoi(argv[1]);
	shared->die = atoi(argv[2]) * 1000;
	shared->eat = atoi(argv[3]) * 1000;
	shared->sleep = atoi(argv[4]) * 1000;
	shared->status = ALIVE;
	if (argc == 6)
		shared->must_eat = atoi(argv[5]);
	else
		shared->must_eat = -1;
	shared->eat_count = 0;
}

void	init_thread(t_philo *philo, t_shared *shared)
{
	int			idx;
	long long	tv;

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
		if (pthread_create(&philo[idx].thread, NULL, \
			run_philo, &philo[idx]) == FAILURE)
			return ;
		idx++;
	}
	monitor(philo, shared);
	idx = -1;
	while (++idx < shared->num)
		pthread_join(philo[idx].thread, NULL);
}

int	init_mutex(t_shared *shared)
{
	int	idx;

	shared->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* shared->num);
	if (!shared->fork)
		return (FAILURE);
	idx = 0;
	while (idx < shared->num)
	{
		if (pthread_mutex_init(&shared->fork[idx], NULL) == FAILURE)
			return (FAILURE);
		idx++;
	}
	if (pthread_mutex_init(&shared->print, NULL) == FAILURE)
		return (FAILURE);
	if (pthread_mutex_init(&shared->flag, NULL) == FAILURE)
		return (FAILURE);
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
		philo[idx].left = idx;
		philo[idx].right = (idx + 1) % shared->num;
		philo[idx].eat_count = 0;
		philo[idx].last_eat = 0;
		philo[idx].shared = shared;
		idx++;
	}
	if (init_mutex(shared) == SUCCESS)
		return (philo);
	return (NULL);
}
