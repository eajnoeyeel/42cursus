/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:54:00 by yeolee2           #+#    #+#             */
/*   Updated: 2023/05/22 02:38:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int isFull(CircularQueue *cq)
{
	return (cq->size == cq->capa);
}

int isEmpty(CircularQueue *cq)
{
	return (cq->size == 0);
}

void	enqueue(int elem, int arr[], CircularQueue *cq)
{
	if (isFull(cq))
	{
		// TODO: Things that need to be done when the queue is full.
	}
	
}

void	preprocess(int argc, char *argv[], CircularQueue *cq)
{
	int	idx;

	cq->capa = argc - 1;
	cq->elem = malloc(cq->capa * sizeof(int));
	idx = 1;
	while (argv[idx])
	{
		if (argv[idx] != ' ')
			cq->elem[idx - 1] = ft_atoi(argv[idx]);
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
}
