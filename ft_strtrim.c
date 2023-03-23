/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:45:47 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/22 21:51:29 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*res;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	if (!*s1)
		return (ft_strdup(""));
	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1) - 1;
	while ((s1[end] && ft_strchr(set, s1[end])) && end > 0)
		end--;
	if (beg > end)
		return (ft_strdup(""));
	res = (char *)malloc(sizeof(char) * (end - beg + 2));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + beg, end - beg + 2);
	return (res);
}
