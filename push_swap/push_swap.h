/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:24:18 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/15 02:50:56 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EMPTY 2147483648
# include "libft/libft.h"

typedef struct	s_stack
{
	int	*elem;
	int	fore;
	int	rear;
	int	capa;
	int	size;
}				t_stack;

typedef struct	s_iota
{
	int	head;
	int	body;
	int	tail;
}				t_iota;

/* INITIALIZE STACK */
void		create_stack(t_stack *cq, int capacity);
void		preprocess(int len, char **res, t_stack *cq);
char		**parse(int *argc, char *argv[]);
void		destroy_stack(t_stack *cq);
void		print_stacks(t_stack *a, t_stack *b);

/* STACK OPERATIONS */
int			isEmpty(t_stack *cq);
int 		isFull(t_stack *cq);
void		push(int element, t_stack *cq);
long long	pop(t_stack *cq);
void		swap(t_stack *cq);
void		reverse(t_stack *cq);
void		rotate(t_stack *cq);

/* SORT OPERATIONS */
void		sort_three_elem(int *arr, t_stack *a, int count);
void		rev_sort_three_elem(int *arr, t_stack *b, int count);
void		sort_two_elem(int *arr, t_stack *a);
void		rev_sort_two_elem(int *arr, t_stack *b);
void		init_iota(t_iota *iota);
void		swap_arr_elem(int *x, int *y);
void		bubble_sort_arr(int *arr, int count);
void		find_pivot(int **arr, int count, int *upper, int *lower);
void		b_to_a(t_stack *a, t_stack *b, int count);
void		a_to_b(t_stack *a, t_stack *b, int count);

/* THE RULES */
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *cq);
void		sb(t_stack *cq);
void		ss(t_stack *a, t_stack *b);
void		ra(t_stack *cq);
void		rb(t_stack *cq);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *cq);
void		rrb(t_stack *cq);
void		rrr(t_stack *a, t_stack *b);

#endif