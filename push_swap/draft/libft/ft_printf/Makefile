# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 02:30:14 by yeolee2           #+#    #+#              #
#    Updated: 2023/06/30 04:12:49 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_utils.c

OBJS	=	${SRCS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libftprintf.a

AR		=	ar -rc

RM		=	rm -rf

DEF_COLOR = \033[0;39m

YELLOW = \033[0;93m

GREEN = \033[1;92m

MAGENTA = \033[0;95m

all		:	${NAME}

%.o		:	%.c
			@echo "${YELLOW}compiling ...${DEF_COLOR}"
			@$(CC) $(CFLAGS) -c -o $@ $<

${NAME} :	${OBJS}
			@${RM} all bonus ${NAME}
			@${AR} ${NAME} ${OBJS}
			@touch all
			@echo "${GREEN}libftprintf made${DEF_COLOR}"

clean   :
			@${RM} ${OBJS} all
			@echo "object files cleaned"

fclean  :	clean
			@${RM} ${NAME}
			@echo "libftprintf archive file cleaned"
			
re		:	fclean all

 .PHONY	:	all re clean .c.o