/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:37:59 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/16 21:07:34 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "ft_printf_utils.c"

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
	else
		return (write(1, "%", 1));
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
	return (len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *buf = (char *)malloc(10);
// 	char *buf2 = (char *)malloc(10);

// 	strcpy(buf, "%p%p%p%p");

// 	printf("\nreturn value of ft_printf: %d\n", ft_printf(buf, buf2));
// 	return (0);
// }

// #include <stdio.h>

// int main()
// {
// 	printf("\nreturn value of printf: %d\n", printf("%x", -10));
// 	printf("\nreturn value of ft_printf: %d\n", ft_printf("%x", -10));
// 	return (0);
// }
