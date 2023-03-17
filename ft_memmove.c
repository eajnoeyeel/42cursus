/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyeonjae <iyeonjae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:19:37 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/03/18 03:28:38 by iyeonjae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	// size_t			idx;
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (csrc == cdst)
		return (dst);
	// if (csrc == NULL && cdst == NULL)
	// 	return (dst);
	if (cdst < csrc)
	{
		// idx = 0;
		// while (idx < len)
		// {
			// cdst[idx] = csrc[idx];
			// idx++;
		// }
		while(len)
		{
			*cdst++ = *csrc++;
			len--;
		}
	}
	else
	{
		cdst += len;
		csrc += len;
		while (len)
		{
			*--cdst = *--csrc;
			len--;
		}
	}
    return (dst);
}
