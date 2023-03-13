/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:10:17 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/13 16:13:56 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*strrchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	while (idx >= 0)
	{
		if (s[idx] == c)
			return (s + idx);
		idx--;
	}
	return (NULL);
}
