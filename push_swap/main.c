/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:55:38 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/12 22:00:14 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_stack_from_args(int len, char **res, t_stack *stack)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		push_front(stack, ft_atoi(res[idx]));
		idx++;
	}
}

char	**parse(int *argc, char *argv[])
{
	int		idx;
	int		len;
	char	*str;
	char	**res;

	idx = 0;
	len = 0;
	if (check_empty_string(argv))
		print_error(2);
	while (++idx < *argc)
		len += ft_strlen(argv[idx]) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	idx = 1;
	while (argv[idx])
	{
		str = ft_strcat(str, argv[idx]);
		if (idx != *argc - 1)
			str = ft_strcat(str, " ");
		idx++;
	}
	*argc = ft_wrdcnt(str, ' ');
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

void	initialize(t_stack **a, t_stack **b)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	if (!*a)
		exit(1);
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!*b)
		exit(1);
	init_stack(*a, 'a');
	init_stack(*b, 'b');
}

void	kill(t_stack *a, t_stack *b, char **res, int argc)
{
	destroy_stack(&a);
	destroy_stack(&b);
	ft_free(res, argc);
}

int	main(int argc, char *argv[])
{
	char	**res;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	initialize(&a, &b);
	res = parse(&argc, argv);
	load_stack_from_args(argc, res, a);
	if (!check_error(res, a))
		print_error(2);
	if (is_sorted(a))
		exit(1);
	a_to_b(a, b, a->size);
	kill(a, b, res, argc);
	return (0);
}
