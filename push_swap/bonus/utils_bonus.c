/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:02:47 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/14 19:40:44 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	exec_command(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
	else
		print_error(2);
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
