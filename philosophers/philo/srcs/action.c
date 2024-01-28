/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:05:52 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 00:10:14 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	feed_philo(philo);
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
