/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:01:20 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/11/07 01:24:20 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				idx;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	if (dst || src)
	{
		cdst = (unsigned char *)dst;
		csrc = (const unsigned char *)src;
		idx = 0;
		while (idx < n)
		{
			cdst[idx] = csrc[idx];
			idx++;
		}
	}
	return (dst);
}
