/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:02:47 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 00:00:43 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	iter;

	iter = a->size;
	if (iter < b->size)
		iter = b->size;
	while (iter)
	{
		if (iter <= a->size)
		{
			ft_printf("%d ", a->tail->data);
			a->tail = a->tail->prev;
		}
		else
			ft_printf("   ");
		ft_printf("   ");
		if (iter <= b->size)
		{
			ft_printf("%d", b->tail->data);
			b->tail = b->tail->prev;
		}
		else
			ft_printf("   ");
		ft_printf("\n");
		iter--;
	}
	ft_printf("_    _\n");
	ft_printf("a    b\n");
}

void	init_stack(t_stack *stack, char name)
{
	stack->flag = 0;
	stack->size = 0;
	stack->name = name;
	stack->head = NULL;
	stack->tail = NULL;
}

void	destroy_stack(t_stack **stack)
{
	t_stack	*goal;
	t_node	*temp;

	goal = *stack;
	while (goal->head)
	{
		temp = goal->head;
		goal->head = goal->head->next;
		free(temp);
	}
	free(goal);
	*stack = NULL;
}
