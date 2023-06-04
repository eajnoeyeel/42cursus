/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monday.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:55:08 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/05 05:44:44 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_iota	iota)
{
	iota.a = 0;
	iota.b = 0;
}

void	sort(t_stack *a, t_stack *b)
{
	int		idx;
	int		chunk;
	int		abide;
	int		round;
	t_iota	iota;
	
	chunk = 1;
	abide = a->size;
	round = 0;
	init(iota);
	while (chunk < a->size)
	{
		while (abide)
		{
			if (abide <= chunk)
			{
				while(abide)
				{
					abide--;
					ra(a);
				}
				break;
			}
			else
			{
				iota.b = chunk;
				idx = 0;
				while (idx < chunk)
				{
					pb(a, b);
					if (idx != 0)
						rb(b);
				}
				abide -= chunk;
				if (abide < chunk)
					iota.a = abide;
				else
					iota.a = chunk;
				abide -= iota.a;
			}
			while (iota.a && iota.b)
			{
				if (a->elem[a->rear] > b->elem[b->rear])
				{
					ra(a);
					iota.a--;
				}
				else
				{
					pa(a, b);
					ra(a);
					iota.b--;
				}
			}
			while (iota.a)
			{
				ra(a);
				iota.a--;
			}
			while (iota.b)
			{
				pa(a, b);
				ra(a);
				iota.b--;
			}
		}
		round++;
		chunk *= 2;
		abide = a->size;
	}
}
