/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:12:16 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/06 21:39:30 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	preprocess_b(t_stack *a, t_stack *b, int count, t_pivot *pivot)
{
	int	*arr;

	b->flag = 0;
	arr = ft_intdup(b, count);
	if (!arr)
		return (1);
	if (count < 4)
	{
		if (count == 3)
			rev_sort_top_three(arr, b);
		else if (count == 2)
			rev_sort_two_elem(arr, b);
		while (count--)
			push(b, a);
		if (arr)
			free(arr);
		return (1);
	}
	find_pivot(&arr, count, &(pivot->upper), &(pivot->lower));
	if (arr)
		free(arr);
	return (0);
}

int	preprocess_a(t_stack *a, int count, t_pivot *pivot)
{
	int	*arr;

	arr = ft_intdup(a, count);
	if (!arr)
		return (1);
	if (count < 4)
	{
		if (count == 3)
			sort_top_three(arr, a);
		else if (count == 2)
			sort_two_elem(arr, a);
		a->flag = 1;
		if (arr)
			free(arr);
		return (1);
	}
	find_pivot(&arr, count, &(pivot->upper), &(pivot->lower));
	if (arr)
		free(arr);
	return (0);
}
