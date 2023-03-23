/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:49:35 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/23 01:08:23 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	idx;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		res[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		res[ft_strlen(s1) + idx] = s2[idx];
		idx++;
	}
	res[ft_strlen(s1) + idx] = 0;
	return (res);
}
