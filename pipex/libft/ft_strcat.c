/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 01:28:22 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/09 01:33:43 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest + ft_strlen(dest);
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (dest);
}
