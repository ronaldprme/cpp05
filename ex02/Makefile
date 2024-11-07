# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:03:23 by rprocopi          #+#    #+#              #
#    Updated: 2024/11/06 16:43:15 by rprocopi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	Bureaucrat

SOURCE			= 	main.cpp \
					Bureaucrat.cpp \
					AForm.cpp \
					ShrubberyCreationForm.cpp \
					RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp
                    

OBJECT			=	$(SOURCE:.cpp=.o)

COMPILE			= 	g++

FLAGS			= 	-Wall -Wextra -Werror -std=c++98

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m

# Regras do Makefile
all: $(NAME)

$(NAME): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!"
	@echo "Executable				./$(NAME) $(RESET)"

%.o: %.cpp
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT)
	@echo "$(ORANGE)Object files removed!$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(ORANGE)Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re