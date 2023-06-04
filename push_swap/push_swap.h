/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 04:24:18 by yeolee2           #+#    #+#             */
/*   Updated: 2023/06/05 06:05:54 by yeolee2          ###   ########.fr       */
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

typedef	struct	s_iota
{
	int	a;
	int	b;
}				t_iota;

int 		isFull(t_stack *cq);
int			isEmpty(t_stack *cq);
int			ft_getmin(t_stack *cq);
void		push(int element, t_stack *cq);
long long	pop(t_stack *cq);
void		preprocess(int argc, char *argv[], t_stack *cq);
void		destroy_stack(t_stack *cq);
void		swap(t_stack *cq);
void		rotate(t_stack *cq);
void		reverse(t_stack *cq);
void		sa(t_stack *cq);
void		sb(t_stack *cq);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *cq);
void		rb(t_stack *cq);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *cq);
void		rrb(t_stack *cq);
void		rrr(t_stack *a, t_stack *b);
void		print_stacks(t_stack *a, t_stack *b);
void		ft_merge(t_stack *a, t_stack *b, t_iota pos);
void		ft_optimize(t_stack *a);
void		ft_sort(t_stack *a, t_stack *b);

#endif