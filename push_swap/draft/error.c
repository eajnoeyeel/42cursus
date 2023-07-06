/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 04:28:52 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/06 21:23:32 by yeolee2          ###   ########.fr       */
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

void	check_dig(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(ft_isdigit(str[i][j]) || str[i][j] == '+' || str[i][j] == '-'))
				print_error(2);
			if ((str[i][j] >= 9 && str[i][j] <= 13) || str[i][j] == 32)
				print_error(2);
			j++;
		}
		i++;
	}
	return ;
}

void	check_dup(t_stack *stack)
{
	t_node	*temp;
	t_node	*curr;
	
	curr = stack->head;
	while (curr)
	{
		temp = curr->next;
		while (temp)
		{
			if (curr->data == temp->data)
				print_error(2);
			temp = temp->next;
		}
		curr = curr->next;
	}
}

// Return true when the error is checked.
int	check_error(char **res, t_stack *stack)
{
	check_dig(res);
	check_dup(stack);
	return (1);
}
