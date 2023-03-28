/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:23:53 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/28 22:48:12 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

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

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*tmp;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	tmp = str;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = 0;
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;
	char	*p;

	idx = 0;
	p = s;
	while (idx < n)
	{
		p[idx] = 0;
		idx++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}