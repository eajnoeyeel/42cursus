/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:02:47 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/05 02:42:02 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int		flag;
	t_node	*temp;

	flag = 0;
	temp = a->tail;
	while (temp->prev)
	{
		if (temp->data > temp->prev->data)
		{
			flag = 1;
			break ;
		}
		temp = temp->prev;
	}
	if (flag)
		return (0);
	return (1);
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
	if (goal)
		free(goal);
	*stack = NULL;
}
