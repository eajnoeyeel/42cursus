# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 16:11:51 by yeolee2           #+#    #+#              #
#    Updated: 2024/04/28 18:50:07 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = megaphone.cpp
OBJS        = $(SRCS:.cpp=.o)
CXX         = c++
INCLUDES    = megaphone.hpp
CFLAGS      = -Wall -Wextra -Werror
NAME        = megaphone
RM          = rm -rf
CYAN        = \033[0;36m
YELLOW      = \033[0;93m
GREEN       = \033[1;92m
MAGENTA     = \033[0;95m

all: $(NAME)

%.o: %.cpp $(INCLUDES)
	@$(CXX) $(CFLAGS) -c -o $@ $< &>/dev/null

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Mandatory Compilation done"

clean:
	@$(RM) $(OBJS)
	@echo "Object files cleaned✅"

fclean: clean
	@$(RM) $(NAME)
	@echo "Archive files cleaned✅"

re: fclean all

.PHONY: all clean fclean re