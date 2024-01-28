/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:04:22 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/24 23:07:01 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

# define FAILURE -1
# define SUCCESS 0
# define DEAD 1
# define ALIVE 0

typedef struct s_shared
{
	int				num;
	int				die;
	int				eat;
	int				sleep;
	int				status;
	int				must_eat;
	int				eat_count;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	flag;
}	t_shared;

typedef struct	s_philo
{
	int			idx;
	int			left;
	int			right;
	int			eat_count;
	long long	last_eat;
	pthread_t	thread;
	t_shared	*shared;
}	t_philo;

# endif