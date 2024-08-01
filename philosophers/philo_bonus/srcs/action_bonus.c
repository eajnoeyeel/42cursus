/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:05:52 by yeolee2           #+#    #+#             */
/*   Updated: 2024/07/31 22:43:16 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	feed_philo(t_philo *philo)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return ;
	if (print_status(philo, "is eating") == FAILURE)
		return ;
	sem_wait(philo->shared->flag);
	philo->last_eat = tv;
	sem_post(philo->shared->flag);
	wait_philo(philo->shared->eat);
}

int	think_philo(t_philo *philo)
{
	if (print_status(philo, "is thinking") == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	sleep_philo(t_philo *philo)
{
	if (print_status(philo, "is sleeping") == FAILURE)
		return (FAILURE);
	wait_philo(philo->shared->sleep);
	return (SUCCESS);
}

int	grab_fork(t_philo *philo)
{
	sem_wait(philo->shared->fork);
	if (print_status(philo, "has taken a fork") == FAILURE)
	{
		sem_post(philo->shared->fork);
		return (FAILURE);
	}
	sem_wait(philo->shared->fork);
	if (print_status(philo, "has taken a fork") == FAILURE)
	{
		sem_post(philo->shared->fork);
		sem_post(philo->shared->fork);
		return (FAILURE);
	}
	feed_philo(philo);
	sem_post(philo->shared->fork);
	sem_post(philo->shared->fork);
	philo->eat_count++;
	if (philo->eat_count == philo->shared->must_eat)
	{
		philo->shared->eat_count++;
		exit(EXIT_SUCCESS);
	}
	return (SUCCESS);
}
