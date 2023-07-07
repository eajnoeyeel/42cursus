/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:28:47 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/20 22:50:09 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntdig(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*res;
	long long	ln;

	ln = (long long)n;
	len = ft_cntdig(ln);
	res = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		ln *= -1;
		while (len-- > 0 && ln > 0)
		{
			res[len] = ln % 10 + '0';
			ln /= 10;
		}
	}
	while (len-- >= 0 && len != -1)
	{
		res[len] = ln % 10 + '0';
		ln /= 10;
	}
	return (res);
}
