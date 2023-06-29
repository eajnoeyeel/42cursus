/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:09:26 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 04:56:34 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int		flag;
	t_node	*temp;

	flag = 0;
	temp = a->tail;
	while (temp->prev)
	{
		if (temp->data > temp->prev->data)
		{
			flag = 1;
			break ;
		}
		temp = temp->prev;
	}
	if (flag)
		return (0);
	return (1);
}

void	print_command(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(a);
	if (!ft_strncmp(line, "sb\n", 3))
		swap(b);
	if (!ft_strncmp(line, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	if (!ft_strncmp(line, "pa\n", 3))
		push(b, a);
	if (!ft_strncmp(line, "pb\n", 3))
		push(a, b);
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(a);
	if (!ft_strncmp(line, "rb\n", 3))
		rotate(b);
	if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	if (!ft_strncmp(line, "rra\n", 4))
		reverse(a);
	if (!ft_strncmp(line, "rrb\n", 4))
		reverse(b);
	if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
}

int	main(int argc, char *argv[])
{
	char	*line;
	char	**res;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	initialize(&a, &b);
	init_stack(a, 'c');
	init_stack(b, 'c');
	res = parse(&argc, argv);
	load_stack_from_args(argc, res, a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		print_command(line, a, b);
		free(line);
	}
	if (!is_sorted(a) || b->size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	exit(0);
}
