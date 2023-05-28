/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:54:00 by yeolee2           #+#    #+#             */
/*   Updated: 2023/05/29 03:07:15 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isFull(t_stack *cq)
{
	return (cq->size == cq->capa);
}

int isEmpty(t_stack *cq)
{
	return (cq->size == 0);
}

void	createQueue(t_stack *cq, int capacity)
{
	cq->elem = (int *)malloc(capacity * sizeof(int));
	cq->fore = -1;
	cq->rear = -1;
	cq->capa = capacity;
	cq->size = 0;
}

void	push(int element, t_stack *cq)
{
	// TODO: Things that need to be done when the queue is full.
	if (isFull(cq))
		return ;
	if (cq->rear == -1)
		cq->fore = 0;
	cq->fore = (cq->fore - 1 + cq->capa) % cq->capa;
	cq->elem[cq->fore] = element;
	cq->size++;
}

long long	pop(t_stack *cq)
{
	int	element;

	if (isEmpty(cq))
		//What TODO: when there is nothing to pop?
		return (ERROR);
	element = cq->elem[cq->fore];
	if (cq->fore == cq->rear)
	{
		cq->fore = -1;
		cq->rear = -1;
	}
	else
	{
		cq->fore = (cq->fore + 1) % cq->capa;
		cq->size--;
	}
	return (element);
}

void	preprocess(int argc, char *argv[], t_stack *cq)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				push(ft_atoi(&argv[i][j]), cq);
				cq->size++;
			}
			j++;
		}
		i++;
	}
}

void	destroyQueue(t_stack *cq)
{
	free(cq->elem);
	free(cq);
}

void	swap(t_stack *cq)
{
	int	tmp1;
	int	tmp2;
	
	if (cq->size < 2)
		return ;
	tmp1 = pop(cq);
	tmp2 = pop(cq);
	push(tmp1, cq);
	push(tmp2, cq);
}

void	sa(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	swap(cq);
	ft_printf("sa\n");
}

void	sb(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	swap(cq);
	ft_printf("sb\n");
}

void	ss(t_stack *cq_a, t_stack *cq_b)
{
	// FIXME: if condition needs to be clarified
	if (cq_a->size < 2 && cq_b->size < 2)
		return ;
	swap(cq_a);
	swap(cq_b);
	ft_printf("ss\n");
}

void	pa(t_stack *cq_a, t_stack *cq_b)
{
	long long	tmp;

	tmp = pop(cq_b);
	if (tmp == ERROR)
		return ;
	push(tmp, cq_a);
	ft_printf("pa\n");
}

void	pb(t_stack *cq_a, t_stack *cq_b)
{
	long long	tmp;

	tmp = pop(cq_a);
	if (tmp == ERROR)
		return ;
	push(tmp, cq_b);
	ft_printf("pb\n");
}

void	rotate(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	cq->rear = cq->fore;
	cq->fore = (cq->fore + 1) % cq->capa;
}

void	ra(t_stack *cq)
{
	rotate(cq);
	ft_printf("ra\n");
}

void	rb(t_stack *cq)
{
	rotate(cq);
	ft_printf("rb\n");
}

void	rr(t_stack *cq_a, t_stack *cq_b)
{
	rotate(cq_a);
	rotate(cq_b);
	ft_printf("rr\n");
}

void	reverse(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	cq->fore = cq->rear;
	cq->rear = (cq->rear - 1 + cq->capa) % cq->capa;
}

void	rra(t_stack *cq)
{
	reverse(cq);
	ft_printf("rra");
}

void	rrb(t_stack *cq)
{
	reverse(cq);
	ft_printf("rrb");
}

void	rrr(t_stack *cq_a, t_stack *cq_b)
{
	reverse(cq_a);
	reverse(cq_b);
	ft_printf("rrr");
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *queue_a;
	t_stack	*queue_b;

	queue_a = malloc(sizeof(t_stack));
	queue_b = malloc(sizeof(t_stack));

	createQueue(queue_a, argc - 1);
	createQueue(queue_b, argc - 1);

	preprocess(argc, argv, queue_a);
	for (int i = 0; i < queue_a->size; i++)
	{
		printf("%d\n", (queue_a->elem)[i]);
	}
	printf("size: %d\n", queue_a->size);
	return (0);
}
