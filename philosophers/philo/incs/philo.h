/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:04:22 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 01:32:53 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Standard library includes for IO, process control, and memory management */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/* Thread handling and time utilities */
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

/* Macro definitions for common return values and boolean logic */
# define FAILURE -1
# define SUCCESS 0
# define DEAD 1
# define ALIVE 0
# define TRUE 1
# define FALSE 0

/* Structure for shared resources and settings among philosophers */
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

/* Structure for each philosopher */
typedef struct s_philo
{
	int			idx;
	int			left;
	int			right;
	int			eat_count;
	long long	last_eat;
	pthread_t	thread;
	t_shared	*shared;
}	t_philo;

/* Function declarations for philosophers' lifecycle and utility functions */
int			grab_fork(t_philo *philo);
int			init_mutex(t_shared *shared);
int			sleep_philo(t_philo *philo);
int			think_philo(t_philo *philo);
int			is_dead(int idx, t_philo *philo, t_shared *shared);
int			print_status(t_philo *philo, char *status);
long long	get_curr_time(void);
t_philo		*init_philo(t_shared *shared);
void		*run_philo(void *arg);
void		destroy_mutex(t_shared *shared);
void		feed_philo(t_philo *philo);
void		free_philo_and_cleanup(t_philo *philo, t_shared *shared);
void		init_thread(t_philo *philo, t_shared *shared);
void		monitor(t_philo *philo, t_shared *shared);
void		parse_arg(int argc, char *argv[], t_shared *shared);
void		wait_philo(long long time);

#endif