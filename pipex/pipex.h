/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyeonjae <iyeonjae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 05:43:40 by iyeonjae          #+#    #+#             */
/*   Updated: 2023/07/18 06:06:46 by iyeonjae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_cmd
{
	char			**cmd;
	char			*head;
	struct s_cmd	*next;
}					t_cmd;

#endif