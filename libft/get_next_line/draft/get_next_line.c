/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:02:50 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/17 18:00:19 by yeolee2          ###   ########.fr       */
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

char	*extract_line(char **tmp)
{
	char	*buf;
	char	*res;
	size_t	idx;

	idx = 0;
	// First read, when tmp is not allocated
	if (!*tmp)
		return (NULL);
	// During read, when tmp is allocated but no remain
	if (!(*tmp)[idx])
	{
		free(*tmp);
		*tmp = NULL;
		return (NULL);
	}
	// Loop to get the index of the first \n
	while ((*tmp)[idx])
	{
		if((*tmp)[idx] == '\n')
			break;
		idx++;
	}
	// Extract tmp from 0 to idx
	res = ft_substr(*tmp, 0, idx + 1);
	// Free tmp when EOF, otherwise save the rest and realloc tmp with the updated content
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
	return (res);
}

char	*preprocessed_line(char **res, char buf[], char **tmp)
{
	// Once preprocessed, calloc tmp for further usage in ft_strjoin
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
	
	// Error handling
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	// do while len
	len = 1;
	while (len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		// Preprocess if read() returns error while reading the file
		if (len < 0)
		{
			// Free allocated tmp if exists
			if (tmp)
				free(tmp);
			// Prevent dangling pointer
			tmp = NULL;
			return (NULL);
		}
		// Once read, contents should be stored in buf, thus treats buf as string for further usage
		buf[len] = 0;
		// Preprocess if read() returns zero inside the loop, indicating EOF
		if (!len)
			break ;
		res = preprocessed_line(&res, buf, &tmp);
		if (is_new_line(tmp))
			break ;
	}
	res = extract_line(&tmp);
	return (res);
}

// int main()
// {
// 	// char	buf[1024];
// 	char	*line;

// 	// read(2, buf, 100);
// 	while ((line = get_next_line(0)))
// 	{
// 		printf( "%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	// system("leaks a.out");
//     // close(fd);
// 	// sleep(1);
// 	return 0;
// }
