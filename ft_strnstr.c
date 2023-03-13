/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:09:28 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/13 18:29:21 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;

	while (!*needle)
		return (haystack);
	idx = 0;
	while (idx < len)
	{
		if (haystack[idx] == needle[0] && !ft_strncmp(haystack + idx, needle, ft_strlen(needle)))
			return (&haystack[idx]);
		idx++;	
	}
	return (NULL);
}
