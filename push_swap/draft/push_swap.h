/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:24:18 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/19 01:19:34 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EMPTY 2147483648
# include "libft/libft.h"

typedef struct	s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct	s_stack
{
	int				size;
	char			name;
	struct s_node	*head;
	struct s_node	*tail;
}				t_stack;

typedef struct	s_iota
{
	int	head;
	int	body;
	int	tail;
}				t_iota;

/* INITIALIZE STACK */
void	init_stack(t_stack *stack);
void	preprocess(int len, char **res, t_stack *stack);
char	**parse(int *argc, char *argv[]);
void	destroy_stack(t_stack **stack);
void	print_stacks(t_stack *a, t_stack *b);

/* STACK OPERATIONS */
void	push_front(t_stack *stack, int content)
void	push_back(t_stack *stack, int content)
void	pop_front(t_stack *stack)
void	pop_back(t_stack *stack)
void	push(t_stack *stack1, t_stack *stack2)
void	swap(t_stack *stack)
void	rotate(t_stack *stack)
void	reverse(t_stack *stack)

/* SORTING OPERATIONS */
void	sort_three_elem(int *arr, t_stack *a, int count)
void	rev_sort_three_elem(int *arr, t_stack *b, int count)
void	sort_two_elem(int *arr, t_stack *a)
void	rev_sort_two_elem(int *arr, t_stack *b)
void	swap_arr_elem(int *x, int *y)
void	init_iota(t_iota *iota)
void	bubble_sort_arr(int *arr, int count)
void	find_pivot(int **arr, int count, int *upper, int *lower)
void	b_to_a(t_stack *a, t_stack *b, int count)
void	a_to_b(t_stack *a, t_stack *b, int count)

// /* THE RULES */
// void		pa(t_stack *a, t_stack *b);
// void		pb(t_stack *a, t_stack *b);
// void		sa(t_stack *cq);
// void		sb(t_stack *cq);
// void		ss(t_stack *a, t_stack *b);
// void		ra(t_stack *cq);
// void		rb(t_stack *cq);
// void		rr(t_stack *a, t_stack *b);
// void		rra(t_stack *cq);
// void		rrb(t_stack *cq);
// void		rrr(t_stack *a, t_stack *b);

#endif