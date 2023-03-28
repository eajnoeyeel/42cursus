/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:23:37 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/28 23:14:14 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *res)
{
	size_t	idx;

	idx = 0;
	while (res[idx])
	{
		if (res[idx] == '\n')
			return (1);
		idx++;
	}
	return (0);
}

char	*extract_line(char *tmp, char *res)
{
	size_t	idx;

	while (tmp[idx])
	{
		if (tmp[idx] == '\n')
			break ;
		idx++;
	}
	// Extract tmp from 0 to idx
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		len;
	char		*res;
	static char	*tmp;

	// Since tmp is freed from the previous call,
	if (!tmp)
		tmp = (char *)ft_calloc(1, sizeof(char) * 1);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		// Preprocessing
		if (len < 0)
			return (NULL);
		else if (!len)
			break ;
		// Once preprocessed, store buf in tmp
		res = ft_strjoin(tmp, buf);
		if (res)
		{
			free(tmp);
			tmp = res;
		}
		else
			return (NULL);
		if (is_new_line(tmp))
			break ;
	}
	// Extract res from tmp when is_new_line() returns TRUE
	return (res);
}