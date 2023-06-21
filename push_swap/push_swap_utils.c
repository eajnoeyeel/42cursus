/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 04:29:13 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/20 07:48:05 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: Sort only the top three elements
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
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		if (arr[1] >= arr[2])
			sa(a);
	}
	else if (arr[0] <= arr[1] && arr[1] >= arr[2])
	{
		ra(a);
		sa(a);
		rra(a);
		if (arr[0] >= arr[2])
			sa(a);
	}
	else
		sa(a);
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
		sb(b);
		rb(b);
		sb(b);
		rrb(b);
		if (arr[1] >= arr[2])
			sb(b);
	}
	else if (arr[0] >= arr[1] && arr[1] <= arr[2])
	{
		rb(b);
		sb(b);
		rrb(b);
		if (arr[0] >= arr[2])
			sb(b);
	}
	else
		sb(b);
}

void	sort_two_elem(int *arr, t_stack *a)
{
	if (arr[0] > arr[1])
		sa(a);
	return ;
}

void	rev_sort_two_elem(int *arr, t_stack *b)
{
	if (arr[0] < arr[1])
		sb(b);
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
	// TODO: Sort the array and find pivot at its 1/3 and 2/3 points
	bubble_sort_arr(*arr, count);
	*lower = (*arr)[count / 3];
	*upper = (*arr)[count / 3 * 2];
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	int		idx;
	int		upper;
	int		lower;
	int		*arr;
	t_iota	iota;

	arr = ft_intdup(a->elem, a->rear, a->size, count);
	if (count <= 2)
	{
		// TODO: Sort 3 in reversed order
		rev_sort_three_elem(arr, b, count);
		while (count--)
			pa(a, b);
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	init_iota(&iota);
	while (count--)
	{
		// Smallest
		if (b->elem[b->rear] <= lower)
		{
			rb(b);
			iota.head++;
		}
		// Everything bigger than the lower pivot
		else
		{
			pa(a, b);
			iota.body++;
			if (b->elem[b->rear] <= upper)
			{
				ra(a);
				iota.tail++;
			}
		}
	}
	a_to_b(a, b, iota.body - iota.tail);
	idx = -1;
	while (++idx < iota.tail)
		rra(a);
	idx = -1;
	while (++idx < iota.head)
		rrb(b);
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
	
	arr = ft_intdup(a->elem, a->rear, a->size, count);
	if (count <= 3)
	{
		// TODO: Sort 3
		sort_three_elem(arr, a, count);
		return ;
	}
	find_pivot(&arr, count, &upper, &lower);
	init_iota(&iota);
	while (count--)
	{
		// Largest
		if (a->elem[a->rear] > upper)
		{
			ra(a);
			iota.head++;
		}
		else
		{
			pb(a, b);
			iota.body++;
			if (a->elem[a->rear] >= lower)
			{
				// if (b->size != 1)
				rb(b);
				iota.tail++;
			}
		}
	}
	idx = -1;
	while (++idx < iota.tail)
		rrb(b);
	idx = -1;
	while (++idx < iota.head)
		rra(a);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
	b_to_a(a, b, iota.body - iota.tail);
}
