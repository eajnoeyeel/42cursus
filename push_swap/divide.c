/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:25:22 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/05 03:14:28 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_b(t_stack *a, t_stack *b, t_iota *iota, t_pivot pivot)
{
	if (b->tail->data < pivot.lower)
	{
		if (b->flag)
		{
			rr(a, b);
			b->flag = 0;
		}
		else
			rotate(b);
		(*iota).tail++;
	}
	else
	{
		if (b->flag)
		{
			rotate(a);
			b->flag = 0;
		}
		(*iota).body += push(b, a);
		if (a->tail->data < pivot.upper)
		{
			b->flag = 1;
			(*iota).head++;
		}
	}
}

void	divide_a(t_stack *a, t_stack *b, t_iota *iota, t_pivot pivot)
{
	if (a->tail->data > pivot.upper)
	{
		if (b->flag)
		{
			rr(a, b);
			b->flag = 0;
		}
		else
			rotate(a);
		(*iota).head++;
	}
	else
	{
		if (b->flag)
		{
			rotate(b);
			b->flag = 0;
		}
		(*iota).body += push(a, b);
		if (b->tail->data > pivot.lower)
		{
			b->flag = 1;
			(*iota).tail++;
		}
	}
}

void	b_to_a(t_stack *a, t_stack *b, int count)
{
	t_pivot	pivot;
	t_iota	iota;

	if (preprocess_b(a, b, count, &pivot))
		return ;
	init_iota(&iota);
	while (count--)
		divide_b(a, b, &iota, pivot);
	if (b->flag)
	{
		rotate(a);
		b->flag = 0;
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
		divide_a(a, b, &iota, pivot);
	if (b->flag)
	{
		rotate(b);
		b->flag = 0;
	}
	recursive_a(a, b, iota);
}
