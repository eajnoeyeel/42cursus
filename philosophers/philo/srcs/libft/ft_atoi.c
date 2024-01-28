/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 02:19:24 by yeolee2           #+#    #+#             */
/*   Updated: 2023/10/31 01:26:59 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(int e)
{
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
		print_error(2);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	if (neg * res > 2147483647 || neg * res < -2147483648)
		print_error(2);
	return (neg * res);
}
