# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 12:50:59 by rchampli          #+#    #+#              #
#    Updated: 2022/12/08 00:12:30 by rchampli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC = $(shell find . -type f -name "*.cpp" | cut -c 3-)

CC = c++

FLAG = -Werror -Wall -Wextra -std=c++98

INCLUDES = $(shell find . -type f -name "*.hpp" | cut -c 3-)

OBJS	= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME): $(OBJS) $(INCLUDES)
			@$(CC) $(FLAG) -o $(NAME) $(OBJS)
%.o: %.cpp $(INCLUDES)
	$(CC) $(FLAG) -c $< -o $@

clean:
			@rm -f $(OBJS)

fclean: clean
			@rm -f $(NAME)

re:	fclean all
