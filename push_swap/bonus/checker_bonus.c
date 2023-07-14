/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 04:09:26 by yeolee2           #+#    #+#             */
/*   Updated: 2023/07/14 19:35:53 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	initialize_checker(t_stack **a, t_stack **b)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(*a, 'c');
	init_stack(*b, 'c');
}

int	main(int argc, char *argv[])
{
	char	*line;
	char	**res;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	initialize_checker(&a, &b);
	res = parse(&argc, argv);
	load_stack_from_args(argc, res, a);
	if (!check_error(res, a))
		print_error(2);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		exec_command(line, a, b);
		free(line);
	}
	if (!is_sorted(a) || b->size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	exit(0);
}
