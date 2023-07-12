/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 05:07:17 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 01:29:18 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_a(t_stack *a, t_stack *b, t_iota iota)
{
	reverse_optimize(a, b, iota);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
	b_to_a(a, b, iota.body - iota.tail);
}

void	recursive_b(t_stack *a, t_stack *b, t_iota iota)
{
	a_to_b(a, b, iota.body - iota.head);
	reverse_optimize(a, b, iota);
	a_to_b(a, b, iota.head);
	b_to_a(a, b, iota.tail);
}
