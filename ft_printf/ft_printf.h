/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:41:09 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/15 01:52:57 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_specifier(va_list ap, char c);
int		ft_printf(const char *format, ...);
int		ft_putchar(unsigned char c);
int		ft_putstr(char *s);
int		ft_putaddr(unsigned long long addr);
int		ft_putnbr(long long n);
int		ft_putupperhex(unsigned int n);
int		ft_putlowerhex(unsigned int n);
int		ft_putunsigned(unsigned int n);

#endif