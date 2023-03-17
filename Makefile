# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 23:09:19 by yeolee2           #+#    #+#              #
#    Updated: 2023/03/17 00:18:02 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_bzero.c ft_memset.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_atoi.c ft_isdigit.c ft_strlcat.c ft_isalnum.c ft_isprint.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c ft_strlen.c ft_tolower.c ft_substr.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

TARGET	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	includes

RM		=	rm -rf

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $(TARGET) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

clean :
	$(RM) : $(OBJS)

fclean :	clean
	$(RM) : $(NAME)

re :	fclean all

.PHONY :	all clean fclean re