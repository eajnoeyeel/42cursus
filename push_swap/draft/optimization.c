/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:29:44 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 02:27:17 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_optimize(t_stack *a, t_stack *b, t_iota iota)
{
	int	idx;

	idx = -1;
	if (a->flag)
	{
		if (iota.head < iota.tail)
		{
			while (++idx < iota.head)
				rrr(a, b);
			while (idx++ < iota.tail)
				reverse(b);
		}
		else
		{
			while (++idx < iota.tail)
				rrr(a, b);
			while (idx++ < iota.head)
				reverse(a);
		}
	}
	else
	{
		while (++idx < iota.tail)
			reverse(b);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	a->name = 'z';
	b->name = 'z';
	rotate(a);
	rotate(b);
	a->name = 'a';
	b->name = 'b';
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	a->name = 'z';
	b->name = 'z';
	reverse(a);
	reverse(b);
	a->name = 'a';
	b->name = 'b';
	ft_printf("rrr\n");
}
