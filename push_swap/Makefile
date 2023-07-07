# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 03:50:12 by yeolee2           #+#    #+#              #
#    Updated: 2023/07/07 05:09:35 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	preprocess.c deque.c divide.c error.c main.c operation.c\
				optimization.c pivot.c recursive.c sort.c utils.c

BONUS		=	bonus/checker_bonus.c bonus/deque_bonus.c bonus/divide_bonus.c\
				bonus/error_bonus.c bonus/operation_bonus.c bonus/optimization_bonus.c\
				bonus/pivot_bonus.c bonus/preprocess_bonus.c bonus/recursive_bonus.c\
				bonus/sort_bonus.c bonus/utils_bonus.c\

OBJS		= 	${SRCS:.c=.o}

BOBJS		=	${BONUS:.c=.o}

CC			= 	cc

INCLUDES	=	push_swap.h

CFLAGS		= 	-Wall -Wextra -Werror -g3 -I${INCLUDES}

NAME        = 	push_swap

LIBFT       = 	libft

ARCHIVE		= 	libft.a

AR			= 	ar -rc

RM			= 	rm -rf

CYAN		= 	\033[0;36m

YELLOW 		= 	\033[0;93m

GREEN		= 	\033[1;92m

MAGENTA		= 	\033[0;95m

all		:		${NAME}

%.o		:		%.c
				@echo "${YELLOW}Compiling..."
				@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :		${OBJS}
				@make all -C $(LIBFT)/
				@$(CC) $(CFLAGS) -o $@ $^ ${LIBFT}/${ARCHIVE}
				@echo "${GREEN}Mandatory Compilation done"

bonus	:		${BOBJS}
				@make all -C $(LIBFT)/
				@$(CC) $(CFLAGS) -o checker $^ ${LIBFT}/${ARCHIVE}
				@echo "${GREEN}Bonus compilation done"

clean   :
				@${RM} ${OBJS} ${BOBJS}
				@make fclean -C ${LIBFT}
				@echo "Object files cleaned✅"

fclean  :		clean
				@${RM} ${NAME}
				@${RM} checker
				@echo "Archive files cleaned✅"

re		:		fclean all

 .PHONY	:		all clean fclean re .c.o