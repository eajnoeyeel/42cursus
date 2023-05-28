/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:23:37 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/07 16:33:56 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* #include "get_next_line_utils.c" */

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

char	*extract_line(char **tmp)
{
	char	*buf;
	char	*res;
	size_t	idx;

	idx = 0;
	res = 0;
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
	// Extract tmp from 0 to idx
	res = ft_substr(*tmp, 0, idx + 1);
	// EOF while read
	if (!(*tmp)[idx])
	{
		free(*tmp);
		*tmp = NULL;
		return (res);
	}
	else
	{
		buf = ft_substr(*tmp, idx + 1, ft_strlen(*tmp));
		free(*tmp);
		*tmp = buf;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		len;
	char		*res;
	static char	*tmp[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Since tmp[fd] is freed from the previous call,
	len = 1;
	res = 0;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		// buf[len] = 0;
		// Preprocessing
		if (len < 0)
		{
			if (tmp[fd])
				free(tmp[fd]);
			tmp[fd] = NULL;
			return (NULL);
		}
		buf[len] = 0;
		if (!len)
			break ;
		// Once preprocessed, store buf in tmp[fd]
		if (!tmp[fd])
		{
			tmp[fd] = (char *)malloc(sizeof(char) * 1);
			if (!tmp[fd])
				return (NULL);
			*tmp[fd] = 0;
		}
		if (tmp[fd])
		{
			res = ft_strjoin(tmp[fd], buf);
			if (res)
			{
				free(tmp[fd]);
				tmp[fd] = res;
			}
			else
				return (NULL);
		}
		else
			return (NULL);
		if (is_new_line(tmp[fd]))
			break ;
	}
	// Break out of loop and extract res from tmp when is_new_line() returns TRUE
	// char *extract_line(char *tmp, char *res);
	res = extract_line(&tmp[fd]);
	return (res);
}

/* int main()
{
    int fd = open("test", O_RDONLY);
    char *line;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	system("leaks a.out");
    close(fd);
    return 0;
}
 */