/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:04:22 by yeolee2           #+#    #+#             */
/*   Updated: 2024/01/29 00:44:32 by yeolee2          ###   ########seoul.kr  */
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
# define TRUE 1
# define FALSE 0

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

void	free_philo_and_cleanup(t_philo *philo, t_shared *shared);
void	destroy_mutex(t_shared *shared);
void	*run_philo(void *arg);
int	print_status(t_philo *philo, char *status);

void	feed_philo(t_philo *philo);
int	think_philo(t_philo *philo);
int	sleep_philo(t_philo *philo);
int	grab_fork(t_philo *philo);

int		is_dead(int idx, t_philo *philo, t_shared *shared);
void	monitor(t_philo *philo, t_shared *shared);

long long	get_curr_time(void);
void	wait_philo(long long time);

void	parse_arg(int argc, char *argv[], t_shared *shared);
void	init_thread(t_philo *philo, t_shared *shared);
int	init_mutex(t_shared *shared);
t_philo	*init_philo(t_shared *shared);

# endif