/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:57:09 by yeolee2           #+#    #+#             */
/*   Updated: 2024/08/01 21:42:50 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	print_status(t_philo *philo, char *status)
{
	long long	tv;

	tv = get_curr_time();
	if (tv == FAILURE)
		return (FAILURE);
	if (is_dead(philo, philo->shared))
		exit(EXIT_FAILURE);
	sem_wait(philo->shared->print);
	printf("%lld %d %s\n", (tv - philo->shared->start_time) / 1000, \
		philo->idx + 1, status);
	sem_post(philo->shared->print);
	return (SUCCESS);
}

void	run_philo(t_philo *philo)
{
	if (philo->shared->num == 1)
	{
		print_status(philo, "has taken a fork");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (grab_fork(philo) == FAILURE)
			exit(EXIT_FAILURE);
		if (sleep_philo(philo) == FAILURE || think_philo(philo) == FAILURE)
			exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	close_semaphore(t_shared *shared)
{
	sem_close(shared->fork);
	sem_close(shared->print);
	sem_close(shared->flag);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("flag");
}

void	free_philo_and_cleanup(t_philo *philo, t_shared *shared)
{
	free(shared->pids);
	free(philo);
	close_semaphore(shared);
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_shared	shared;

	if (argc == 5 || argc == 6)
	{
		parse_arg(argc, argv, &shared);
		if (shared.num <= 0 || shared.die <= 0 || shared.eat <= 0 \
			|| shared.sleep <= 0 || (argc == 6 && shared.must_eat <= 0))
			return (EXIT_FAILURE);
		philo = init_philo(&shared);
		if (philo)
			init_process(philo, &shared);
		free_philo_and_cleanup(philo, &shared);
	}
	else
	{
		printf("Error: Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
