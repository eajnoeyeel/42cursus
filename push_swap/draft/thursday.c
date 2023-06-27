/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thursday.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 04:55:38 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/27 05:03:20 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preprocess(int len, char **res, t_stack *stack)
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
	return (res);
}

int main(int argc, char *argv[])
{
	char	**res;
	t_stack *a;
	t_stack *b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));

	init_stack(a, 'a');
	init_stack(b, 'b');

	res = parse(&argc, argv);
	preprocess(argc, res, a);
	a_to_b(a, b, a->size);
	// swap(a);
	// push(a, b);
	// push(a, b);
	// push(a, b);
	// rrr(a, b);
	print_stacks(a, b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	if (*s2 == '+')
// 		s2++;
// 	while (s1 || s2)
// 	{
// 		if (*s1 != *s2)
// 			return (1);
// 		s1++;
// 		s2++;
// 	}
// 	return (0);
// }

// void asd{
// 	while (i < ac)
// 	{
// 		tmp = ft_split(av[i], " ");
// 		while (tmp[j])
// 		{
// 			ret = atoi(tmp);
// 			if (itoa(ret) != tmp[j])
// 			{
// 				free_split()
// 				return ;
// 			}
// 			i++;
// 			push ret;
// 		}
// 		freesplit();
// 	}
	
// }