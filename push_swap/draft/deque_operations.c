/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:23:09 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/27 05:27:26 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, int content)
{
	t_node	*temp;
	
	temp = (t_node *)malloc(sizeof(t_stack));
	temp->data = content;
	temp->prev = NULL;
	if (!stack->head)
	{
		stack->head = temp;
		stack->tail = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack->head;
		stack->head->prev = temp;
		stack->head = temp;
	}
	stack->size++;
}

void	push_back(t_stack *stack, int content)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_stack));
	temp->data = content;
	temp->next = NULL;
	if (!stack->head)
	{
		stack->head = temp;
		stack->tail = temp;
		temp->prev = NULL;
	}
	else
	{
		stack->tail->next = temp;
		temp->prev = stack->tail;
		stack->tail = temp;
	}
	stack->size++;
}

void	pop_front(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head)
		return ;
	else if (stack->size == 1)
	{
		free(stack->head);
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		temp = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		free(temp);
	}
	stack->size--;
}

void	pop_back(t_stack *stack)
{
	t_node	*temp;

	if (!stack->head)
		return ;
	else if (stack->size == 1)
	{
		free(stack->head);
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		temp = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		free(temp);
	}
	stack->size--;
}
