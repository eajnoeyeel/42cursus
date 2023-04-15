/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:43:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/15 01:54:19 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long long addr)
{
	int		tmp;
	int		len;
	int		idx;
	char	res[17];

	tmp = write(1, "0x", 2);
	if (tmp == -1)
		return (tmp);
	if (!addr)
		return (tmp + write(1, "0", 1));
	idx = 0;
	while (addr)
	{
		res[idx++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	res[idx] = 0;
	len = 0;
	while (idx--)
	{
		if (write(1, &res[idx], 1) == -1)
			return (-1);
		len++;
	}
	return (tmp + len);
}

int	ft_putnbr(long long n)
{
	int		tmp;
	size_t	len;

	len = 0;
	tmp = 0;
	if (n < 0)
	{
		n = -n;
		tmp = write(1, "-", 1);
		if (tmp == -1)
			return (-1);
		len += ft_putnbr(n);
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
		len++;
	}
	else
	{
		ft_putchar(n % 10 + '0');
		len++;
	}
	return (tmp + len);
}

int	ft_putunsigned(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putunsigned(n / 10);
		ft_putchar(n % 10 + '0');
		len++;
	}
	else
	{
		ft_putchar(n % 10 + '0');
		len++;
	}
	return (len);
}

int	ft_putlowerhex(unsigned int n)
{
	int	tmp;
	int	len;

	len = 0;
	tmp = 0;
	if (!n)
		return (write(1, "0", 1));
	if (n < 16)
		return (write(1, &"0123456789abcdef"[n], 1));
	len += ft_putlowerhex(n / 16);
	tmp = write(1, &"0123456789abcdef"[n % 16], 1);
	if (tmp == -1)
		return (tmp);
	return (tmp + len);
}

int	ft_putupperhex(unsigned int n)
{
	int	tmp;
	int	len;

	len = 0;
	tmp = 0;
	if (!n)
		return (write(1, "0", 1));
	if (n < 16)
		return (write(1, &"0123456789ABCDEF"[n], 1));
	len += ft_putupperhex(n / 16);
	tmp = write(1, &"0123456789ABCDEF"[n % 16], 1);
	if (tmp == -1)
		return (tmp);
	return (tmp + len);
}
