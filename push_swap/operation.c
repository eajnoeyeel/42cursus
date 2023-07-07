/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:27:29 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/03 23:17:40 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *stack1, t_stack *stack2)
{
	if (!stack1->size)
		return (0);
	if (stack2->name == 'a')
		ft_printf("pa\n");
	else if (stack2->name == 'b')
		ft_printf("pb\n");
	push_back(stack2, stack1->tail->data);
	pop_back(stack1);
	return (1);
}

void	swap(t_stack *stack)
{
	int	old;
	int	new;

	if (stack->size < 2)
		return ;
	if (stack->name == 'a')
		ft_printf("sa\n");
	else if (stack->name == 'b')
		ft_printf("sb\n");
	old = stack->tail->data;
	new = stack->tail->prev->data;
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
	else if (stack->name == 'b')
		ft_printf("rb\n");
	if (stack->size < 2)
		return ;
	temp = stack->tail->data;
	pop_back(stack);
	push_front(stack, temp);
}

void	reverse(t_stack *stack)
{
	int	temp;

	if (stack->name == 'a')
		ft_printf("rra\n");
	else if (stack->name == 'b')
		ft_printf("rrb\n");
	if (stack->size < 2)
		return ;
	temp = stack->head->data;
	pop_front(stack);
	push_back(stack, temp);
}
