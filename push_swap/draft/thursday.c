/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thursday.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:55:38 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/19 01:17:28 by yeolee2          ###   ########.fr       */
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

// push from stack1 to stack2
void	push(t_stack *stack1, t_stack *stack2)
{
	if (!stack1->size)
		return ;
	if (stack2->name == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
	push_back(stack2, stack1->tail->data);
	pop_back(stack1);
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

void	init_stack(t_stack *stack)
{
	stack->name = 'a';
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	destroy_stack(t_stack **stack)
{
	t_stack	*goal;
	t_node	*temp;

	goal = *stack;
	while (goal->head)
	{
		temp = goal->head;
		free(temp->data);
		goal->head = goal->head->next;
		free(temp);
	}
	free(goal);
	*stack = NULL;
}

void	preprocess(int len, char **res, t_stack *stack)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		push_back(stack, ft_atoi(res[idx]));
		idx++;
	}
}

char	**parse(int *argc, char *argv[])
{
	int		idx;
	int		len;
	char	*str;
	char	**res;

	idx = 0;
	len = 0;
	while (++idx < *argc)
		len += ft_strlen(argv[idx]) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	idx = 1;
	while (argv[idx])
	{
		str = ft_strcat(str, argv[idx]);
		if (idx != *argc - 1)
			str = ft_strcat(str, " ");
		idx++;
	}
	*argc = ft_wrdcnt(str, ' ');
	res = ft_split(str, ' ');
	return (res);
}

int main(int argc, char *argv[])
{
	char	**res;
	t_stack *a;
	t_stack *b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));

	init_stack(a);
	init_stack(b);

	res = parse(&argc, argv);
	preprocess(argc, res, a);
	a_to_b(a, b, a->size);
	print_stacks(a, b);
	return (0);
}