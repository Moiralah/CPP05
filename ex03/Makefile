# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 23:24:00 by huidris           #+#    #+#              #
#    Updated: 2025/11/06 20:04:03 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= form

FLAGS	= -Wall -Wextra -Werror -std=c++11

CC		= c++

SRC		= Bureaucrat.cpp main.cpp AForm.cpp ShruberryCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear
	rm -f *_shruberry

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
