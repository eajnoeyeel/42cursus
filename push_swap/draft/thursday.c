/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thursday.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:55:38 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/15 05:38:32 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *stack, int content)
{
	t_node	*temp;
	
	temp = (t_stack *)malloc(sizeof(t_stack));
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

	temp = (t_stack *)malloc(sizeof(t_stack));
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

void	push(t_stack *stack1, t_stack *stack2)
{
	if (stack2->size)
		return ;
	if (stack1->name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	push_back(stack1, stack2->tail->data);
	pop_back(stack2);
}

void	swap(t_stack *stack)
{
	int	old;
	int	new;

	if (stack->size < 2)
		return ;
	if (stack->name == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	old = stack->tail->data;
	new = stack->tail->prev->tail->data;
	pop_back(stack);
	pop_back(stack);
	push_back(stack, old);
	push_back(stack, new);
}

void	rotate(t_stack *stack)
{
	int	temp;
	
	if (stack->name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	if (stack->size < 2)
		return ;
	temp = stack->tail->data;
	pop_back(stack);
	push_front(stack, temp);
}

void	reverse(t_stack *stack)
{
	int temp;

	if (stack->name == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	if (stack->size < 2)
		return ;
	temp = stack->head->data;
	pop_front(stack);
	push_back(stack, temp);
}
