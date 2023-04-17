/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:43:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/17 15:32:29 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long long addr)
{
	int		len;
	int		idx;
	char	res[16];

	if (write(1, "0x", 2) == -1)
		return (-1);
	len = 2;
	if (!addr)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	idx = 0;
	while (addr)
	{
		res[idx++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	len += idx;
	while (idx--)
		if (write(1, &res[idx], 1) == -1)
			return (-1);
	return (len);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		if (write(1, "-", 1) == -1)
			return (-1);
		len = ft_putnbr(n);
		if (len == -1)
			return (-1);
	}
	else if (n > 9)
	{
		len = ft_putnbr(n / 10);
		if (len == -1)
			return (-1);
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	}
	else
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	len++;
	return (len);
}

int	ft_putunsigned(unsigned int n)
{
	int	tmp;
	int	len;

	len = 0;
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	}
	else
		if (ft_putchar(n % 10 + '0') == -1)
			return (-1);
	len++;
	return (len);
}

int	ft_putlowerhex(unsigned int n)
{
	int	tmp;
	int	len;

	len = 0;
	tmp = 0;
	if (n > 15)
	{
		tmp = ft_putlowerhex(n / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = write(1, &"0123456789abcdef"[n % 16], 1);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}

int	ft_putupperhex(unsigned int n)
{
	int	tmp;
	int	len;

	len = 0;
	tmp = 0;
	if (n > 15)
	{
		tmp = ft_putupperhex(n / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = write(1, &"0123456789ABCDEF"[n % 16], 1);
	if (tmp == -1)
		return (-1);
	len += tmp;
	return (len);
}
