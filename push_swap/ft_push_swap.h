/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:54:40 by yeolee2           #+#    #+#             */
/*   Updated: 2023/05/22 02:13:02 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct
{
	int	*elem;
    int fore;
    int rear;
	int	capa;
	int	size;
}	CircularQueue;

#endif