/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 01:54:33 by yeolee2           #+#    #+#             */
/*   Updated: 2023/11/15 17:57:46 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long    ft_hextol(const char *str)
{
	long    res;

	res = 0;
	if (ft_strncmp(str, "0x", 2))
		str += 2;
	while (*str)
	{
		res = res << 4;
		if (*str >= '0' && *str <= '9')
			res += *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			res += *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			res += *str - 'A' + 10;
		++str;
	}
	return (res);
}
