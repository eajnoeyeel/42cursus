/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:39:40 by yeolee2           #+#    #+#             */
/*   Updated: 2023/03/22 18:36:59 by yeolee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;
	t_list	*temp;

	head = *lst;
	while (head)
	{
		temp = head;
		del(temp->content);
		head = head->next;
		free(temp);
	}
	if (head)
		free(head);
	*lst = NULL;
}
