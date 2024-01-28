/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:08:57 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 00:41:23 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_dead(int idx, t_philo *philo, t_shared *shared)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return ;
	pthread_mutex_lock(&shared->flag);
	if (tv - philo[idx].last_eat > shared->die)
	{
		shared->status = DEAD;
		printf("%lld %d %s\n", (tv - shared->start_time) / 1000, philo[idx].idx + 1, "died");
		pthread_mutex_unlock(&shared->flag);
		return (TRUE);
	}
	if (shared->eat_count == shared->num)
	{
		shared->status = DEAD;
		printf("%lld %d %s\n", (tv - shared->start_time) / 1000, philo[idx].idx + 1, "is full");
		pthread_mutex_unlock(&shared->flag);
		return (TRUE);
	}
	pthread_mutex_unlock(&shared->flag);
	return (FALSE);
}

void	monitor(t_philo *philo, t_shared *shared)
{
	int			idx;

	while (1)
	{
		idx = 0;
		while (idx < shared->num)
		{
			if (is_dead(idx, philo, shared) == TRUE)
				return ;
			idx++;
		}
	}
}
