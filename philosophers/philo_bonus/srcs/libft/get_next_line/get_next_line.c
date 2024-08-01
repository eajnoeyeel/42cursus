/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:02:50 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/03 05:58:48 by yeolee2          ###   ########.fr       */
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

void	postprocess(char **tmp, size_t idx, char *buf)
{
	if (!(*tmp)[idx])
	{
		free(*tmp);
		*tmp = NULL;
	}
	else
	{
		buf = ft_substr(*tmp, idx + 1, ft_strlen(*tmp));
		free(*tmp);
		*tmp = buf;
	}
}

char	*extract_line(char **tmp)
{
	char	*buf;
	char	*res;
	size_t	idx;

	idx = 0;
	if (!*tmp)
		return (NULL);
	if (!(*tmp)[idx])
	{
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
	while ((*tmp)[idx])
	{
		if ((*tmp)[idx] == '\n')
			break ;
		idx++;
	}
	res = ft_substr(*tmp, 0, idx + 1);
	buf = 0;
	postprocess(tmp, idx, buf);
	return (res);
}

char	*preprocessed_line(char **res, char buf[], char **tmp)
{
	if (!*tmp)
		*tmp = (char *)ft_calloc(1, sizeof(char));
	if (*tmp)
	{
		*res = ft_strjoin(*tmp, buf);
		if (*res)
		{
			free(*tmp);
			*tmp = *res;
			return (*res);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*res;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		len;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			if (tmp)
				free(tmp);
			tmp = NULL;
			return (NULL);
		}
		buf[len] = 0;
		res = preprocessed_line(&res, buf, &tmp);
		if (is_new_line(tmp) || !len)
			break ;
	}
	return (extract_line(&tmp));
}
