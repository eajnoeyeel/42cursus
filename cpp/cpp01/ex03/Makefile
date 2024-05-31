# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeolee2 <yeolee2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:38:54 by yeolee2           #+#    #+#              #
#    Updated: 2024/05/30 17:39:05 by yeolee2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS        = srcs/main.cpp
OBJS        = $(SRCS:.cpp=.o)
CXX         = c++
INCLUDES    = ./incs
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDES) -std=c++98
NAME        = zombie
RM          = rm -rf
CYAN        = \033[0;36m
YELLOW      = \033[0;93m
GREEN       = \033[1;92m
MAGENTA     = \033[0;95m
RESET       = \033[0m

all: $(NAME)

%.o: %.cpp
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CXX) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Mandatory Compilation done$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files cleaned✅$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)Archive files cleaned✅$(RESET)"

re: fclean all

.PHONY: all clean fclean re
