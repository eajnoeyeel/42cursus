/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:37:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/22 05:00:24 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	idx;
	int	tmp;
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	if (!*s)
		return (write(1, "", 0));
	idx = 0;
	len = 0;
	while (s[idx])
	{
		tmp = ft_putchar(s[idx]);
		if (tmp == -1)
			return (-1);
		idx++;
		len += tmp;
	}
	return (len);
}

int	ft_specifier(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putaddr((unsigned long long)va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_putlowerhex(va_arg(ap, unsigned int)));
	else if (c == 'X')
		return (ft_putupperhex(va_arg(ap, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		idx;
	int		len;
	int		tmp;
	va_list	ap;

	va_start(ap, format);
	idx = 0;
	len = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			tmp = ft_specifier(ap, format[idx + 1]);
			idx++;
		}
		else
			tmp = ft_putchar(format[idx]);
		if (tmp == -1)
			return (tmp);
		else
			len += tmp;
		idx++;
	}
	va_end(ap);
	return (len);
}
