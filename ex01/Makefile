# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 23:24:00 by huidris           #+#    #+#              #
#    Updated: 2025/09/06 03:09:57 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= form

FLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= c++

SRC		= Bureaucrat.cpp main.cpp form.cpp

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
