/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:05:05 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 01:06:42 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_sort_only_three(int *arr, t_stack *b)
{
	if (arr[0] >= arr[1] && arr[1] >= arr[2])
		return ;
	else if (arr[0] <= arr[1] && arr[0] <= arr[2])
	{
		rotate(b);
		if (arr[1] <= arr[2])
			swap(b);
	}
	else if (arr[0] >= arr[1] && arr[1] <= arr[2])
	{
		reverse(b);
		if (arr[0] >= arr[2])
			swap(b);
	}
	else
		swap(b);
}

void	rev_sort_top_three(int *arr, t_stack *b)
{
	if (arr[0] >= arr[1] && arr[1] >= arr[2])
		return ;
	else if (arr[0] <= arr[1] && arr[0] <= arr[2])
	{
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
	if (a->size < 2)
		return ;
	if (arr[0] > arr[1])
		swap(a);
	return ;
}

void	rev_sort_two_elem(int *arr, t_stack *b)
{
	if (b->size < 2)
		return ;
	if (arr[0] < arr[1])
		swap(b);
	return ;
}

void	sort_top_three(int *arr, t_stack *a)
{
	if (arr[0] <= arr[1] && arr[1] <= arr[2])
		return ;
	else if (arr[0] >= arr[1] && arr[0] >= arr[2])
	{
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
