/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:29:34 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/19 01:45:42 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
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
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	if ( str[idx] || res > 2147483647 || res < -2147483648)
		print_error();
	return (neg * res);
}
