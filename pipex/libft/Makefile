# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 23:09:19 by yeolee2           #+#    #+#              #
#    Updated: 2023/07/07 04:54:40 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c\
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcat.c\
			ft_printf/ft_printf.c ft_printf/ft_printf_utils.c\
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\

BONUS	 =	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\

OBJS	=	${SRCS:.c=.o}

BOBJS	=	${OBJS} ${BONUS:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

AR		=	ar -rc

RM		=	rm -rf

all		:	${NAME}

${NAME} :	${OBJS}
			@${RM} all bonus ${NAME}
			@${AR} ${NAME} ${OBJS}

bonus	:	@${BOBJS}
			@${RM} all bonus ${NAME}
			@${AR} ${NAME} ${BOBJS}

clean   :
			@${RM} ${BOBJS} all bonus

fclean  :	clean
			@${RM} ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re .c.o

.SILENT	:	${OBJS}