/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:25:22 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 04:06:24 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	preprocess_b(t_stack *a, t_stack *b, int count, t_pivot *pivot)
{
	int	*arr;

	arr = ft_intdup(b, count);
	if (count < 4)
	{
		if (count == 3)
			rev_sort_top_three(arr, b);
		else if (count == 2)
			rev_sort_two_elem(arr, b);
		while (count--)
			push(b, a);
		free(arr);
		return (1);
	}
	find_pivot(&arr, count, &(pivot->upper), &(pivot->lower));
	free(arr);
	return (0);
}

int	preprocess_a(t_stack *a, int count, t_pivot *pivot)
{
	int	*arr;

	arr = ft_intdup(a, count);
	if (count < 4)
	{
		if (count == 3)
			sort_top_three(arr, a);
		else if (count == 2)
			sort_two_elem(arr, a);
		a->flag = 1;
		free(arr);
		return (1);
	}
	find_pivot(&arr, count, &(pivot->upper), &(pivot->lower));
	free(arr);
	return (0);
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	t_pivot	pivot;
	t_iota	iota;

	if (preprocess_b(a, b, count, &pivot))
		return ;
	init_iota(&iota);
	while (count--)
	{
		if (b->tail->data < pivot.lower)
		{
			rotate(b);
			iota.tail++;
		}
		else
		{
			iota.body += push(b, a);
			if (a->tail->data < pivot.upper)
			{
				rotate(a);
				iota.head++;
			}
		}
	}
	recursive_b(a, b, iota);
}

void	a_to_b(t_stack *a, t_stack *b, int count)
{
	t_iota	iota;
	t_pivot	pivot;

	if (preprocess_a(a, count, &pivot))
		return ;
	init_iota(&iota);
	while (count--)
	{
		if (a->tail->data > pivot.upper)
		{
			rotate(a);
			iota.head++;
		}
		else
		{
			iota.body += push(a, b);
			if (b->tail->data > pivot.lower)
			{
				rotate(b);
				iota.tail++;
			}
		}
	}
	recursive_a(a, b, iota);
}

// void	a_to_b(t_stack *a, t_stack *b, int count)
// {
// 	t_iota	iota;
// 	t_pivot	pivot;

// 	if (preprocess_a(a, count, &pivot))
// 		return ;
// 	init_iota(&iota);
// 	while (count--)
// 	{
// 		if (b->flag == 1 && a->tail->data <= pivot.upper)
// 			rotate(b);
// 		else if (a->tail->data > pivot.upper && b->flag == 1)
// 		{
// 			rr(a, b);
// 			iota.head++;
// 		}
// 		else if (a->tail->data > pivot.upper && b->flag == 0)
// 		{
// 			rotate(a);
// 			iota.head++;
// 		}
// 		else
// 		{
// 			iota.body += push(a, b);
// 			if (b->tail->data > pivot.lower)
// 			{
// 				b->flag = 1;
// 				iota.tail++;
// 			}
// 			else
// 				b->flag = 0;
// 		}
// 	}
// 	if (b->flag == 1)
// 		rotate(b);
// 	recursive_a(a, b, iota);
// }
