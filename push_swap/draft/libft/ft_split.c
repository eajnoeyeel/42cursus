/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:28:09 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/24 02:43:25 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdcnt(char *str, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if (str[idx] != c && (str[idx + 1] == c || str[idx + 1] == '\0'))
			cnt++;
		idx++;
	}
	return (cnt);
}

char	*ft_strncpy(char *dst, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (src[idx] && idx < n)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (dst);
}

char	**ft_free(char **str, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		free(str[idx]);
		idx++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*beg;
	size_t	idx;

	idx = 0;
	res = (char **)malloc(sizeof(char *) * (ft_wrdcnt((char *)s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			beg = (char *)s;
			while (*s && (*s != c))
				s++;
			*(res + idx) = (char *)malloc(sizeof(char) * ((s - beg) + 1));
			if (!*(res + idx))
				return (ft_free(res, idx));
			ft_strncpy(*(res + idx++), beg, s - beg);
		}
		else
			s++;
	}
	res[idx] = NULL;
	return (res);
}
