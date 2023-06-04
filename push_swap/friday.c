/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   friday.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:44:02 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/05 05:57:04 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef	struct	s_iota
{
	int	left;
	int	mean;
	int	dext;
}				t_iota;

int	ft_get_max_of_three_elem(int arr[3])
{
	int	res;
	
	res = arr[0];
	if (res < arr[1])
		res = arr[1];
	if (res < arr[2])
		res = arr[2];
	return (res);
}

void	merge_stack_edges(t_stack *a, t_stack *b)
{
	int	max;
	int	arr[3];

	arr[0] = a->elem[a->rear];
	arr[1] = a->elem[a->fore];
	arr[2] = b->elem[b->fore];
	max = ft_get_max_of_three_elem(arr);
	if (max == arr[0])
		pb(a, b);
	else if (max == arr[1])
	{
		rra(a);
		pb(a, b);
	}
	else
		rrb(b);
}

void	ft_merge(t_stack *a, t_stack *b, t_iota pos)
{
	int	i;
	int	j;

	i = pos.left;
	j = pos.mean + 1;
	while (i <= pos.mean && j < pos.dext)
	{
		if (a->elem[a->fore - i] > a->elem[a->fore - j])
			pb(a, b);
		else
			ra(a);
	}
	while (i++ <= pos.mean)
	// {
		ra(a);
	// 	i++;
	// }
	while (j++ <= pos.dext)
	// {
		pb(a, b);
	// 	j++;
	// }
	while (b->size > 0)
		pa(a, b);
}

int	ft_getmin(t_stack *a)
{
	int	min;
	int	idx;

	min = a->elem[a->rear];
	idx = 0;
	while (idx < a->size)
	{
		if (min > a->elem[idx])
			min = a->elem[idx];
		idx++;
	}
	return (min);
}

void	ft_optimize(t_stack *a)
{
	int	idx;
	int	rot;
	
	rot = 0;
	while (a->elem[a->fore - rot] != ft_getmin(a))
		rot++;
	if (rot > a->size / 2)
		rot = a->size - rot;
	idx = 0;
	while (idx < rot)
	{
		ra(a);
		idx++;
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	int		iter;
	t_iota	pos;

	iter = 1;
	while (iter < a->size)
	{
		pos.left = 0;
		while (pos.left + iter)
		{
			pos.mean = pos.left + iter - 1;
			if (pos.left + 2 * iter - 1 < (a->size - 1))
				pos.dext = (pos.left + 2 * iter - 1);
			else
				pos.dext = a->size - 1;
			ft_optimize(a);
			ft_merge(a, b, pos);
			pos.left += 2 * iter;
		}
		iter *= 2;
	}
}