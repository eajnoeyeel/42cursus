/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:05:05 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/27 05:32:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_sort_only_three(int *arr, t_stack *b)
{
	// 3 2 1
	if (arr[0] >= arr[1] && arr[1] >= arr[2])
		return ;
	else if (arr[0] <= arr[1] && arr[0] <= arr[2])
    {
        // Elements need to be reversed
        // 1 3 2
        rotate(b);
		// 1 2 3
        if (arr[1] <= arr[2])
            swap(b);
    }
    else if (arr[0] >= arr[1] && arr[1] <= arr[2])
    {
        // 2 1 3
        reverse(b);
        if (arr[0] >= arr[2])
            // 3 1 2
            swap(b);
    }
	// 2 3 1
    else
        swap(b);
}

void	rev_sort_top_three(int *arr, t_stack *b, int count)
{
	if (count < 3)
	{
		if (count == 2)
			rev_sort_two_elem(arr, b);
		return ;
	}
	// 3 2 1
	if (arr[0] >= arr[1] && arr[1] >= arr[2])
		return ;
	// 1 3 2
	else if (arr[0] <= arr[1] && arr[0] <= arr[2])
	{
		// Elements need to be reversed
		swap(b);
		rotate(b);
		swap(b);
		reverse(b);
		// 1 2 3
		if (arr[1] <= arr[2])
			swap(b);
	}
	// 3 1 2
	else if (arr[0] >= arr[1] && arr[1] <= arr[2])
	{
		rotate(b);
		swap(b);
		reverse(b);
		// 2 1 3
		if (arr[0] <= arr[2])
			swap(b);
	}
	// 2 3 1
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

void    sort_top_three(int *arr, t_stack *a, int count)
{
    // for (int idx = 0; idx < count; idx++)
    //  printf("arr[%d]: %d\n", idx, arr[idx]);
    if (count < 3)
    {
        if (count == 2)
            sort_two_elem(arr, a);
        return ;
    }
    // 1 2 3
    if (arr[0] <= arr[1] && arr[1] <= arr[2])
        return ;
    else if (arr[0] >= arr[1] && arr[0] >= arr[2])
    {
        // Elements need to be reversed
        // 3 1 2
        swap(a);
        rotate(a);
        swap(a);
        reverse(a);
        if (arr[1] >= arr[2])
            // 3 2 1
            swap(a);
    }
    else if (arr[0] <= arr[1] && arr[1] >= arr[2])
    {
        // 1 3 2
        rotate(a);
        swap(a);
        reverse(a);
        if (arr[0] >= arr[2])
            // 2 3 1
            swap(a);
    }
	// 2 1 3
    else
        swap(a);
}