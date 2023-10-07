/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 02:19:24 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/06 02:01:00 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(int e)
{
	write(0, "Hi:)\n", 5);
	write(e, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			idx;
	int			neg;
	long long	res;

	idx = 0;
	res = 0;
	neg = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg *= -1;
		idx++;
	}
	if (str[idx] < '0' || str[idx] > '9')
	{
		ft_printf("!%d!", idx);
		write(0, &str[idx], 1);
		print_error(2);
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	if (str[idx] == '\n' || neg * res > 2147483647 || neg * res < -2147483648)
	{
		write(0, "Hi:2\n", 5);
		print_error(2);
	}
	return (neg * res);
}
