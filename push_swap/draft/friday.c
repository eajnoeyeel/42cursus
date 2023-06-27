/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friday.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:21:07 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/27 05:30:03 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_iota(t_iota *iota)
{
	iota->head = 0;
	iota->body = 0;
	iota->tail = 0;
}

void	swap_arr_elem(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	bubble_sort_arr(int *arr, int count)
{
	int	i;
	int	j;
    int	flag;

	i = -1;
	while (++i < count - 1)
	{
		flag = 0;
		j = -1;
		while (++j < count - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				swap_arr_elem(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		// If no two elements were swapped by inner loop,
        // then break
		if (!flag)
			break ;
	}
}

void	find_pivot(int **arr, int count, int *upper, int *lower)
{
	bubble_sort_arr(*arr, count);
	// *lower = (*arr)[(count + 1) / 3 - 1];
	// *upper = (*arr)[(count + 1) / 3 * 2 - 1];
	*lower = (*arr)[count / 3];
	*upper = (*arr)[count / 3 * 2];
}

int	*ft_intdup(t_stack *stack, int count)
{
	t_node	*tmp;
	int		idx;
	int		*res;

	// ft_printf("count: %d\n", count);
	res = (int *)malloc(sizeof(int) * count);
	if (!res)
		return (NULL);
	idx = 0;
	tmp = stack->tail;
	while (count--)
	{
		res[idx] = tmp->data;
		tmp = tmp->prev;
		idx++;
	}
	return (res);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	// int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(b, count);
	// if (b->size == 3)
	// {
	// 	rev_sort_only_three(arr, b);
	// 	while (count--)
	// 		push(b, a);
	// 	return ;	
	// }
	if (count <= 3)
	{
		rev_sort_top_three(arr, b, count);
		while (count--)
			push(b, a);
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	// ft_printf("upper: %d\nlower: %d\n", upper, lower);
	init_iota(&iota);
	while (count--)
	{
		// ft_printf("b->tail->data: %d\n", b->tail->data);
		// Smallest
		if (b->tail->data < lower)
		{
			rotate(b);
			iota.tail++;
		}
		// Everything bigger than the lower pivot
		else
		{
			push(b, a);
			iota.body++;
			// Middle
			if (a->tail->data < upper)
			{
				rotate(a);
				iota.head++;
			}
		}
	}
	// Largest
	a_to_b(a, b, iota.body - iota.head);
	// idx = -1;
	// while (++idx < iota.head)
	// 	reverse(a);
	// idx = -1;
	// while (++idx < iota.tail)
	// 	reverse(b);
	reverse_optimize(a, b, iota);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	// int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(a, count);
	// if (a->size == 3)
	// {
	// 	sort_only_three(arr, a);
	// 	return ;
	// }
	if (count <= 3)
	{
		sort_top_three(arr, a, count);
		a->flag = 1;
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	// ft_printf("upper: %d\nlower: %d\n", upper, lower);
	init_iota(&iota);
	while (count--)
	{
		// Largest
		// ft_printf("a->tail->data: %d\n", a->tail->data);
		if (a->tail->data > upper)
		{
			rotate(a);
			iota.head++;
		}
		else
		{
			// Smallest
			push(a, b);
			iota.body++;
			// Middle
			if (b->tail->data > lower)
			{
				rotate(b);
				iota.tail++;
			}
		}
	}
	reverse_optimize(a, b, iota);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
	b_to_a(a, b, iota.body - iota.tail);
}
