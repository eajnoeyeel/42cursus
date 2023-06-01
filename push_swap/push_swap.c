/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 02:54:00 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/01 01:10:08 by yeolee2          ###   ########.fr       */
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
	if (isEmpty(cq))
	{
		cq->rear = 0;
		cq->fore = 0;
	}
	else
		cq->rear = (cq->rear + 1) % cq->capa;
	cq->elem[cq->rear] = element;
	cq->size++;
}

long long	pop(t_stack *cq)
{
	int	element;

	if (isEmpty(cq))
		// What TODO: when there is nothing to pop?
		return (EMPTY);
	element = cq->elem[cq->rear];
	if (cq->fore == cq->rear)
	{
		cq->fore = -1;
		cq->rear = -1;
	}
	else
		cq->rear = (cq->rear - 1 + cq->capa) % cq->capa;
	cq->size--;
	return (element);
}

void	preprocess(int argc, char *argv[], t_stack *cq)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		push(ft_atoi(argv[i]), cq);
		i--;
	}
}

void	destroyQueue(t_stack *cq)
{
	free(cq->elem);
	free(cq);
}

void	swap(t_stack *cq)
{
	int temp;

	if (cq->size < 2)
		return ;
	temp = cq->elem[cq->rear];
	cq->elem[cq->rear] = cq->elem[(cq->rear - 1 + cq->capa) % cq->capa];
	cq->elem[(cq->rear - 1 + cq->capa) % cq->capa] = temp;
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

void	ss(t_stack *a, t_stack *b)
{
	// FIXME: if condition needs to be clarified
	if (a->size < 2 && b->size < 2)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	long long	tmp;

	tmp = pop(b);
	if (tmp == EMPTY)
		return ;
	push(tmp, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	long long	tmp;

	tmp = pop(a);
	if (tmp == EMPTY)
		return ;
	push(tmp, b);
	ft_printf("pb\n");
}

void	rotate(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	cq->fore = cq->rear;
	cq->rear = (cq->rear - 1 + cq->size) % cq->size;
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

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	reverse(t_stack *cq)
{
	if (cq->size < 2)
		return ;
	cq->rear = cq->fore;
	cq->fore = (cq->fore + 1) % cq->size;
}

void	rra(t_stack *cq)
{
	reverse(cq);
	ft_printf("rra\n");
}

void	rrb(t_stack *cq)
{
	reverse(cq);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
	ft_printf("rrr\n");
}

void	printStacks(t_stack *a, t_stack *b)
{
	int	iter;

	iter = a->size;
	if (iter < b->size)
		iter = b->size;
	while (iter)
	{
		if (iter <= a->size)
			ft_printf("%d", a->elem[(a->fore - 1 + iter) % a->size]);
		else
			ft_printf("   ");
		ft_printf(" ");
		if (iter <= b->size)
			ft_printf("%d", b->elem[(b->fore - 1 + iter) % b->size]);
		else
			ft_printf(" ");
		ft_printf("\n");
		iter--;
	}
	ft_printf("_     _\n");
	ft_printf("a     b\n");
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));

	createQueue(a, 500);
	createQueue(b, 500);

	preprocess(argc, argv, a);
	
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// pb(a, b);
	// rrb(b);
	printStacks(a, b);
	return (0);
}
