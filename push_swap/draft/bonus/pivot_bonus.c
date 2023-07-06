/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:21:07 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/07 02:20:18 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_iota(t_iota *iota)
{
	iota->head = 0;
	iota->body = 0;
	iota->tail = 0;
}

void	swap_arr_elem(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
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
		if (!flag)
			break ;
	}
}

void	find_pivot(int **arr, int count, int *upper, int *lower)
{
	bubble_sort_arr(*arr, count);
	*lower = (*arr)[count / 3];
	*upper = (*arr)[count / 3 * 2];
}

int	*ft_intdup(t_stack *stack, int count)
{
	t_node	*tmp;
	int		idx;
	int		*res;

	res = (int *)malloc(sizeof(int) * count);
	if (!res)
		return (NULL);
	idx = 0;
	tmp = stack->tail;
	while (tmp && count--)
	{
		res[idx] = tmp->data;
		tmp = tmp->prev;
		idx++;
	}
	return (res);
}
