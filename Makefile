# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 11:38:10 by tiacovel          #+#    #+#              #
#    Updated: 2024/04/23 18:08:46 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	$(wildcard src/*.c)

OBJ	= $(SRC:.c=.o)

RM		= rm -f
CC		= cc
CFLAGS	= -pthread -Wall -Wextra -Werror -fsanitize=address #-fsanitize=address #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g -O0 $(OBJ) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -g -O0 -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re