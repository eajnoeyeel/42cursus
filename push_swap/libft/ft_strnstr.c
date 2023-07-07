/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:09:28 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/15 01:40:09 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	int		idx;

	while (!*needle)
		return ((char *)haystack);
	res = ft_substr(haystack, 0, len);
	idx = 0;
	while (res[idx])
	{
		if (res[idx] == needle[0]
			&& !ft_strncmp(res + idx, needle, ft_strlen(needle)))
		{
			free(res);
			return ((char *)&haystack[idx]);
		}
		idx++;
	}
	free(res);
	return (0);
}
