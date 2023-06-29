/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:28:52 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/28 04:20:35 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty_string(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == 0)
			return (1);
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
				break ;
			if (j == (int)ft_strlen(argv[i]) - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(ft_isdigit(str[i][j])
				|| str[i][j] == '+' || str[i][j] == '-'))
				print_error(2);
			if ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
				print_error(2);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_invalid_input(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
				print_error(2);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(char **str, t_stack *stack)
{
	int		idx;
	t_node	*ptr;

	idx = 0;
	ptr = stack->head;
	while (ptr)
	{
		if (ptr->data == ft_atoi(str[idx]))
			print_error(2);
		idx++;
		ptr = ptr->next;
	}
	return (1);
}

int	check_error(char **res, t_stack *stack)
{
	if (!check_digit(res))
		return (1);
	if (!check_duplicate(res, stack))
		return (1);
	if (!check_invalid_input(res))
		return (1);
	return (0);
}
