/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:02:46 by yeolee2           #+#    #+#             */
/*   Updated: 2023/04/03 06:19:32 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		is_new_line(char *res);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*preprocessed_line(char **res, char buf[], char **tmp);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	postprocess(char **tmp, size_t idx, char *buf);

#endif