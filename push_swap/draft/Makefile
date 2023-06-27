# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 03:50:12 by yeolee2           #+#    #+#              #
#    Updated: 2023/06/27 05:28:01 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= thursday.c friday.c deque_operations.c error_utils.c sorting_utils.c stack_operations.c stack_utils.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

CFLAGS		= -g3 -Wall -Wextra -Werror -fsanitize=address

NAME        = push_swap

LIBFT       = libft

ARCHIVE		= libft.a

AR			= ar -rc

RM			= rm -rf

CYAN		= \033[0;36m

YELLOW 		= \033[0;93m

GREEN		= \033[1;92m

MAGENTA		= \033[0;95m

all		:	${NAME}

%.o		:	%.c
			@echo "${YELLOW}Compiling..."
			@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :	${OBJS}
			@make all -C $(LIBFT)/
			@$(CC) $(CFLAGS) -o $@ $^ ${LIBFT}/${ARCHIVE}
			@echo "${GREEN}Compilation done"

clean   :
			@${RM} ${OBJS}
			@make clean -C ${LIBFT}
			@echo "Object files cleaned✅"

fclean  :	clean
			@${RM} ${NAME}
			@${RM} ${LIBFT_LIB}
			@make fclean -C ${LIBFT}
			@echo "Archive files cleaned✅"
			
re		:	fclean all

 .PHONY	:	all re clean .c.o