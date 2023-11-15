# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 17:17:33 by yeolee2           #+#    #+#              #
#    Updated: 2023/11/15 16:07:16 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	fdf.c parse.c rotate.c draw.c hook.c init.c projection.c

# BONUS		=	fdf_bonus.c parse_bonus.c rotate_bonus.c draw_bonus.c hook_bonus.c init_bonus.c projection_bonus.c

OBJS		= 	${SRCS:.c=.o}

BOBJS		=	${BONUS:.c=.o}

CC			= 	cc

INCLUDES	=	fdf.h

# BINCLUDES	=	bonus/pipex_bonus.h

CFLAGS		= 	-Wall -Wextra -Werror -g -g3

NAME        = 	fdf

LIBFT       = 	libft

ARCHIVE		= 	libft.a

MLX			=	minilibx

MLXFLAGS	=	-Lminilibx -lmlx -framework OpenGL -framework Appkit

LIBMLX		=	libmlx.a

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

$(NAME)		: 	$(OBJS) $(LIBFT)/$(ARCHIVE) $(MLX)/$(LIBMLX)
				@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx
				@echo "$(GREEN)Mandatory Compilation done"

$(BOBJS)	:	$(BINCLUDES)

# bonus		: 	$(BOBJS) $(LIBFT)/$(ARCHIVE)
# 				@$(CC) $(CFLAGS) -o pipex $^ -L$(LIBFT) -lft
# 				@echo "$(GREEN)Bonus compilation done"

$(LIBFT)/$(ARCHIVE):
				@make -C $(LIBFT)

$(MLX)/$(LIBMLX):
				@make -C $(MLX)

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
