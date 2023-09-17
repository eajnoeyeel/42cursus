# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 19:53:56 by yeolee2           #+#    #+#              #
#    Updated: 2023/09/12 01:22:33 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	pipex.c process.c

BONUS		=	bonus/pipex_bonus.c bonus/process_bonus.c

OBJS		= 	${SRCS:.c=.o}

BOBJS		=	${BONUS:.c=.o}

CC			= 	cc

INCLUDES	=	pipex.h

CFLAGS		= 	-Wall -Wextra -Werror -g3 -I${INCLUDES}

NAME        = 	pipex

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
				@$(CC) $(CFLAGS) -o pipex $^ ${LIBFT}/${ARCHIVE}
				@echo "${GREEN}Bonus compilation done"

clean   :
				@${RM} ${OBJS} ${BOBJS}
				@make fclean -C ${LIBFT}
				@echo "Object files cleaned✅"

fclean  :		clean
				@${RM} ${NAME}
				@${RM} pipex
				@echo "Archive files cleaned✅"

re		:		fclean all

 .PHONY	:		all clean fclean re .c.o