/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:41:42 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/18 03:57:43 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*p;

	p = (unsigned char *)s;
	idx = 0;
	while (idx < n)
	{
		if (p[idx] == (unsigned char)c)
			return ((unsigned char *)(p + idx));
		idx++;
	}
	return (NULL);
}
