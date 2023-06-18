# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 03:50:12 by yeolee2           #+#    #+#              #
#    Updated: 2023/06/18 00:57:21 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= thursday.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

CFLAGS		= -g -Wall -Wextra -Werror

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