/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friday.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:21:07 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/21 19:19:52 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_three_elem(int *arr, t_stack *a, int count)
{
	// for (int idx = 0; idx < count; idx++)
	// 	printf("arr[%d]: %d\n", idx, arr[idx]);
	if (count == 1)
		return ;
	if (count == 2)
	{
		sort_two_elem(arr, a);
		return ;
	}
	if (a->size < 3)
		return ;
	// 1 2 3
	if (arr[0] <= arr[1] && arr[1] <= arr[2])
		return ;
	else if (arr[0] >= arr[1] && arr[0] >= arr[2])
	{
		// Elements need to be reversed
		swap(a);
		rotate(a);
		swap(a);
		reverse(a);
		if (arr[0] >= arr[2])
			swap(a);
	}
	else if (arr[0] <= arr[1] && arr[1] >= arr[2])
	{
		rotate(a);
		swap(a);
		reverse(a);
		if (arr[0] >= arr[2])
			swap(a);
	}
	else if (arr[2] >= arr[1] && arr[2] >= arr[0])
		swap(a);
}

// int	t_d(t_stack *stack)
// {
// 	return (stack->tail->data);
// }

// int	tp_d(t_stack *stack)
// {
// 	return (stack->tail->prev->data);
// }

// int	tpp_d(t_stack *stack)
// {
// 	return (stack->tail->prev->prev->data);
// }

// void	sort_three(t_stack *a)
// {
// 	if (a->size < 3)
// 		return ;
// 	if (t_d(a) > tp_d(a) && t_d(a) > tpp_d(a))
// 	{
// 		swap(a);
// 		rotate(a);
// 		swap(a);
// 		rotate(a);
// 		if (t_d(a) > tp_d(a))
// 			swap(a);
// 	}
// 	else if (tp_d(a) > t_d(a) && tp_d(a) > tpp_d(a))
// 	{
// 		rotate(a);
// 		swap(a);
// 		rotate(a);
// 		if (t_d(a) > tp_d(a))
// 			swap(a);
// 	}
// 	else
// 	{
// 		if (t_d(a) > tp_d(a))
// 			swap(a);
// 	}
// }

void	rev_sort_three_elem(int *arr, t_stack *b, int count)
{
	// for (int idx = 0; idx < count; idx++)
	// 	printf("arr[%d]: %d\n", idx, arr[idx]);
	if (count == 1)
		return ;
	if (count == 2)
	{
		rev_sort_two_elem(arr, b);
		return ;
	}
	if (arr[0] >= arr[1] && arr[1] >= arr[2])
		return ;
	else if (arr[0] <= arr[1] && arr[0] <= arr[2])
	{
		// Elements need to be reversed
		swap(b);
		rotate(b);
		swap(b);
		reverse(b);
		if (arr[1] <= arr[2])
			swap(b);
	}
	else if (arr[0] >= arr[1] && arr[1] <= arr[2])
	{
		rotate(b);
		swap(b);
		reverse(b);
		if (arr[0] <= arr[2])
			swap(b);
	}
	else
		swap(b);
}

void	sort_two_elem(int *arr, t_stack *a)
{
	if (arr[0] > arr[1])
		swap(a);
	return ;
}

void	rev_sort_two_elem(int *arr, t_stack *b)
{
	if (arr[0] < arr[1])
		swap(b);
	return ;
}

void	swap_arr_elem(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	init_iota(t_iota *iota)
{
	iota->head = 0;
	iota->body = 0;
	iota->tail = 0;
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
	*lower = (*arr)[(count) / 3];
	*upper = (*arr)[(count) / 3 * 2];
}

int	*ft_intdup(t_stack *stack, int count)
{
	t_node	*tmp;
	int		idx;
	int		*res;

	// ft_printf("count: %d\n", count);
	res = (int *)malloc(sizeof(int) * count);
	idx = 0;
	tmp = stack->tail;
	while (count-- && tmp)
	{
		res[idx] = tmp->data;
		tmp = tmp->prev;
		idx++;
	}
	return (res);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(b, count);
	if (count <= 2)
	{
		rev_sort_two_elem(arr, b);
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
		if (b->tail->data <= lower)
		{
			rotate(b);
			iota.head++;
		}
		// Everything bigger than the lower pivot
		else
		{
			push(b, a);
			iota.body++;
			// Middle
			if (a->tail->data <= upper)
			{
				rotate(a);
				iota.tail++;
			}
		}
	}
	// Largest
	a_to_b(a, b, iota.body - iota.tail);
	idx = -1;
	while (++idx < iota.tail)
		reverse(a);
	idx = -1;
	while (++idx < iota.head)
		reverse(b);
	a_to_b(a, b, iota.tail);
	b_to_a(a, b, iota.head);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(a, count);
	if (count <= 3)
	{
		sort_three_elem(arr, a, count);
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	// ft_printf("upper: %d\nlower: %d\n", upper, lower);
	init_iota(&iota);
	while (count--)
	{
		// Largest
		// ft_printf("a->tail->data: %d\n", a->tail->data);
		if (a->tail->data >= upper)
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
			if (b->tail->data >= lower)
			{
				rotate(b);
				iota.tail++;
			}
		}
	}
	idx = -1;
	while (++idx < iota.tail)
		reverse(b);
	idx = -1;
	while (++idx < iota.head)
		reverse(a);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
	b_to_a(a, b, iota.body - iota.tail);
} 
