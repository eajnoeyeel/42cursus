# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 19:53:56 by yeolee2           #+#    #+#              #
#    Updated: 2023/09/22 01:45:46 by yeolee2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.c process.c parse.c

BONUS		=	bonus/main_bonus.c bonus/process_bonus.c bonus/parse_bonus.c bonus/heredoc_bonus.c

OBJS		= 	${SRCS:.c=.o}

BOBJS		=	${BONUS:.c=.o}

CC			= 	cc

INCLUDES	=	pipex.h

BINCLUDES	=	bonus/pipex_bonus.h

CFLAGS		= 	-Wall -Wextra -Werror -g3

NAME        = 	pipex

LIBFT       = 	libft

ARCHIVE		= 	libft.a

AR			= 	ar -rc

RM			= 	rm -rf

CYAN		= 	\033[0;36m

YELLOW 		= 	\033[0;93m

GREEN		= 	\033[1;92m

MAGENTA		= 	\033[0;95m

all			: 	$(NAME)

%.o			: 	%.c $(INCLUDES)
				@echo "$(YELLOW)Compiling..."
				@$(CC) $(CFLAGS) -I$(INCLUDES) -c -o $@ $<

$(NAME)		: 	$(OBJS) $(LIBFT)/$(ARCHIVE)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft
				@echo "$(GREEN)Mandatory Compilation done"

$(BOBJS)	:	$(BINCLUDES)

bonus		: 	$(BOBJS) $(LIBFT)/$(ARCHIVE)
				@$(CC) $(CFLAGS) -o pipex $^ -L$(LIBFT) -lft
				@echo "$(GREEN)Bonus compilation done"

$(LIBFT)/$(ARCHIVE):
				@make -C $(LIBFT)

clean		:
				@$(RM) $(OBJS) $(BOBJS)
				@make clean -C $(LIBFT)
				@echo "Object files cleaned✅"

fclean		: 	clean
				@$(RM) $(NAME)
				@$(RM) pipex
				@make fclean -C $(LIBFT)
				@echo "Archive files cleaned✅"

re			:	fclean all

.PHONY		: 	all clean fclean re .c.o
