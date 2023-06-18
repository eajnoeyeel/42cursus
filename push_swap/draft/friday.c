/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friday.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:21:07 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/19 01:20:12 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elem(int *arr, t_stack *a, int count)
{
	if (count == 2)
	{
		sort_two_elem(arr, a);
		return ;
	}
	if (arr[0] <= arr[1] && arr[1] <= arr[2])
		return ;
	else if (arr[0] >= arr[1] && arr[0] >= arr[2])
	{
		// Elements need to be reversed
		swap(a);
		rotate(a);
		swap(a);
		reverse(a);
		if (arr[1] >= arr[2])
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
	else
		swap(a);
}

void	rev_sort_three_elem(int *arr, t_stack *b, int count)
{
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
		if (arr[1] >= arr[2])
			swap(b);
	}
	else if (arr[0] >= arr[1] && arr[1] <= arr[2])
	{
		rotate(b);
		swap(b);
		reverse(b);
		if (arr[0] >= arr[2])
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
	*lower = (*arr)[count / 3];
	*upper = (*arr)[count /3 * 2];
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(a, count);
	if (count <= 3)
	{
		rev_sort_three_elem(arr, b, count);
		while (count--)
			push(b, a);
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	init_iota(&iota);
	while (count--)
	{
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
			if (b->tail->data <= upper)
			{
				rotate(a);
				iota.tail++;
			}
		}
	}
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
	init_iota(&iota);
	while (count--)
	{
		// Largest
		if (a->tail->data >= upper)
		{
			rotate(a);
			iota.head++;
		}
		else
		{
			push(a, b);
			iota.body++;
			if (a->tail->data >= lower)
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
