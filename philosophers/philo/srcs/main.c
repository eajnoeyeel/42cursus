/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:57:09 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/28 23:11:07 by yeolee2          ###   ########seoul.kr  */
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

long long	get_curr_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == FAILURE)
		return (FAILURE);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	wait_philo(long long time)
{
	long long	tv;
	
	tv = get_curr_time();
	while (get_curr_time() - tv < time)
		usleep(500);
}

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

void	feed_philo(t_philo *philo)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return ;
	if (print_status(philo, "is eating") == FAILURE)
		return ;
	pthread_mutex_lock(&philo->shared->flag);
	philo->last_eat = tv;
	pthread_mutex_unlock(&philo->shared->flag);
	wait_philo(philo->shared->eat);
}

void	think_philo(t_philo *philo)
{
	if (print_status(philo, "is thinking") == FAILURE)
		return ;
}

void	sleep_philo(t_philo *philo)
{
	if (print_status(philo, "is sleeping") == FAILURE)
		return ;
	wait_philo(philo->shared->sleep);
}

int	grab_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->fork[philo->left]);
	if (print_status(philo, "has taken a fork") == FAILURE)
	{
		pthread_mutex_unlock(&philo->shared->fork[philo->left]);
		return (FAILURE);
	}
	pthread_mutex_lock(&philo->shared->fork[philo->right]);
	if (print_status(philo, "has taken a fork") == FAILURE)
	{
		pthread_mutex_unlock(&philo->shared->fork[philo->right]);
		pthread_mutex_unlock(&philo->shared->fork[philo->left]);
		return (FAILURE);
	}
		// TODO: Check fork order
	feed_philo(philo);
		// TODO: Check fork order
	pthread_mutex_unlock(&philo->shared->fork[philo->right]);
	pthread_mutex_unlock(&philo->shared->fork[philo->left]);
	philo->eat_count++;
	if (philo->eat_count == philo->shared->must_eat)
	{
		pthread_mutex_lock(&philo->shared->flag);
		philo->shared->eat_count++;
		pthread_mutex_unlock(&philo->shared->flag);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	*run_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->idx % 2 == 1)
		wait_philo(philo->shared->eat);
	while (1)
	{
		if (grab_fork(philo) == FAILURE)
			return (NULL);
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
}

int	init_mutex(t_shared *shared)
{
	int	idx;

	shared->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * shared->num);
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
		//TODO: Handle init_time() error
		philo[idx].last_eat = 0;
		philo[idx].shared = shared;
		idx++;
	}
	if (init_mutex(shared) == SUCCESS)
		return (philo);
	return (NULL);
}

void	monitor(t_philo *philo, t_shared *shared)
{
	int			idx;
	long long	tv;

	while (1)
	{
		idx = 0;
		while (idx < shared->num)
		{
			tv = get_curr_time();
			if (tv == FAILURE)
				return ;
			pthread_mutex_lock(&shared->flag);
			if (tv - philo[idx].last_eat > shared->die)
			{
				shared->status = DEAD;
				printf("%lld %d %s\n", (tv - shared->start_time) / 1000, philo[idx].idx + 1, "died");
				pthread_mutex_unlock(&shared->flag);
				return ;
			}
			if (shared->eat_count == shared->num)
			{
				shared->status = DEAD;
				printf("%lld %d %s\n", (tv - shared->start_time) / 1000, philo[idx].idx + 1, "is full");
				pthread_mutex_unlock(&shared->flag);
				return ;
			}
			pthread_mutex_unlock(&shared->flag);
			idx++;
		}
	}	
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
		if (pthread_create(&philo[idx].thread, NULL, run_philo, &philo[idx]) == FAILURE)
			return ;
		idx++;
	}
	monitor(philo, shared);
	idx = -1;
	while (++idx < shared->num)
		pthread_join(philo[idx].thread, NULL);
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
	// number_of_philosophers time_to_die time_to_eat time_to_sleep
	// [number_of_times_each_philosopher_must_eat]
	if (argc == 5 || argc == 6)
	{
		parse_arg(argc, argv, &shared);
		philo = init_philo(&shared);
		if (philo)
			init_thread(philo, &shared);
		free_philo_and_cleanup(philo, &shared);
	}
	else
		printf("Error: Wrong number of arguments\n");
	return (0);
}
