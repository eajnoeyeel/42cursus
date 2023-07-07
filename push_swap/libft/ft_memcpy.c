/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:01:20 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/03/18 04:01:15 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;
	char	*cdst;
	char	*csrc;

	if (dst || src)
	{
		cdst = (char *)dst;
		csrc = (char *)src;
		idx = 0;
		while (idx < n)
		{
			cdst[idx] = csrc[idx];
			idx++;
		}
	}
	return (dst);
}
