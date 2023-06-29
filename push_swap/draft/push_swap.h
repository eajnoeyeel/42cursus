/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:24:18 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/30 01:17:36 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	int				flag;
	char			name;
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

typedef struct s_iota
{
	int	head;
	int	body;
	int	tail;
}	t_iota;

typedef struct s_pivot
{
	int	upper;
	int	lower;
}	t_pivot;

/* INITIALIZE STACK */
char	**parse(int *argc, char *argv[]);
int		ft_atoi(const char *str);
void	destroy_stack(t_stack **stack);
void	init_stack(t_stack *stack, char name);
void	load_stack_from_args(int len, char **res, t_stack *stack);
void	print_error(int e);
void	print_stacks(t_stack *a, t_stack *b);

/* STACK OPERATIONS */
void	push_front(t_stack *stack, int content);
void	push_back(t_stack *stack, int content);
void	pop_front(t_stack *stack);
void	pop_back(t_stack *stack);

/* SORTING OPERATIONS */
int		*ft_intdup(t_stack *stack, int count);
int		preprocess_a(t_stack *a, int count, t_pivot *pivot);
int		preprocess_b(t_stack *a, t_stack *b, int count, t_pivot *pivot);
void	a_to_b(t_stack *a, t_stack *b, int count);
void	b_to_a(t_stack *a, t_stack *b, int count);
void	bubble_sort_arr(int *arr, int count);
void	find_pivot(int **arr, int count, int *upper, int *lower);
void	init_iota(t_iota *iota);
void	recursive_a(t_stack *a, t_stack *b, t_iota iota);
void	recursive_b(t_stack *a, t_stack *b, t_iota iota);
void	rev_sort_only_three(int *arr, t_stack *b);
void	rev_sort_top_three(int *arr, t_stack *b);
void	rev_sort_two_elem(int *arr, t_stack *b);
void	reverse_optimize(t_stack *a, t_stack *b, t_iota iota);
void	sort_two_elem(int *arr, t_stack *a);
void	swap_arr_elem(int *x, int *y);
void	sort_top_three(int *arr, t_stack *a);

/* THE RULES */
int		push(t_stack *stack1, t_stack *stack2);
void	rotate(t_stack *stack);
void	reverse(t_stack *stack);
void	swap(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);

/* ERROR HANDLING */
int		check_digit(char **str);
int		check_duplicate(char **str, t_stack *stack);
int		check_empty_string(char *argv[]);
int		check_error(char **res, t_stack *stack);
int		check_invalid_input(char **str);

#endif