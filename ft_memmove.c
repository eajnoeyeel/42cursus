/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:19:37 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/03/18 03:58:24 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (csrc == cdst)
		return (dst);
	if (cdst < csrc)
	{
		idx = 0;
		while (idx < len)
		{
			cdst[idx] = csrc[idx];
			idx++;
		}
	}
	else
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	return (dst);
}
