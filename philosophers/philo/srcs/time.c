/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:03:53 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 00:04:16 by yeolee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
