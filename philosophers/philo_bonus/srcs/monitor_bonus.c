/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:08:57 by yeolee2           #+#    #+#             */
/*   Updated: 2024/08/01 22:02:58 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	is_dead(t_philo *philo, t_shared *shared)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return (FALSE);
	if (tv - philo->last_eat > shared->die)
	{
		sem_wait(philo->shared->print);
		printf("%lld %d %s\n", (tv - shared->start_time) / 1000, \
			philo->idx + 1, "died");
		return (TRUE);
	}
	return (FALSE);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		if (is_dead(philo, philo->shared))
			exit(EXIT_FAILURE);
	}
}
