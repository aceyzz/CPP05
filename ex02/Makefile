#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cedmulle <cedmulle@student.42lsaunne.ch>    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2024#03#01 11:47:26 by cedmulle          #+#    #+#             *#
#*   Updated: 2024#03#01 11:47:35 by cedmulle         ###   ########.ch       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME	= aform
SRC_DIR	= src/
INC_DIR	= inc/
SRC		= $(SRC_DIR)main.cpp \
			$(SRC_DIR)Bureaucrat.cpp \
			$(SRC_DIR)AForm.cpp \
			$(SRC_DIR)ShrubberyCreationForm.cpp \
			$(SRC_DIR)RobotomyRequestForm.cpp \
			$(SRC_DIR)PresidentialPardonForm.cpp
OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		= -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFL) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CFL) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
