/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thursday.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:55:38 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/20 08:15:39 by yeolee2          ###   ########.fr       */
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
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
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

void	init_stack(t_stack *stack, char name)
{
	stack->name = name;
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
		// free(temp->data);
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
		push_front(stack, ft_atoi(res[idx]));
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

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int			idx;
	int			neg;
	long long	res;

	idx = 0;
	res = 0;
	neg = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg *= -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	if ( str[idx] || res > 2147483647 || res < -2147483648)
		print_error();
	return (neg * res);
}

int main(int argc, char *argv[])
{
	char	**res;
	t_stack *a;
	t_stack *b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));

	init_stack(a, 'a');
	init_stack(b, 'b');

	res = parse(&argc, argv);
	preprocess(argc, res, a);
	a_to_b(a, b, a->size);
	//print_stacks(a, b);
	return (0);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	if (*s2 == '+')
// 		s2++;
// 	while (s1 || s2)
// 	{
// 		if (*s1 != *s2)
// 			return (1);
// 		s1++;
// 		s2++;
// 	}
// 	return (0);
// }

// void asd{
// 	while (i < ac)
// 	{
// 		tmp = ft_split(av[i], " ");
// 		while (tmp[j])
// 		{
// 			ret = atoi(tmp);
// 			if (itoa(ret) != tmp[j])
// 			{
// 				free_split()
// 				return ;
// 			}
// 			i++;
// 			push ret;
// 		}
// 		freesplit();
// 	}
	
// }