# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rprocopi <mailto:rprocopi@student.42lis    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 14:03:23 by rprocopi          #+#    #+#              #
#    Updated: 2024/11/01 10:34:42 by rprocopi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	Bureaucrat

SOURCE			= 	main.cpp \
					Bureaucrat.cpp \
					Form.cpp
					

OBJECT			=	$(SOURCE:.cpp=.o)

COMPILE			= 	g++

FLAGS			= 	-Wall -Wextra -Werror -std=c++98

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(NAME)

%.o: %.cpp
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!"
	@echo "Executable				./$(NAME) $(RESET)"

clean:
	@echo "$(RED)--------------------------------------------------------"
	@/bin/rm -f $(OBJECT)
	@echo "$(WHITE)REMOVED O-FILES $(RESET)"

fclean: clean
	@echo "$(RED)--------------------------------------------------------"
	@/bin/rm -f $(NAME)
	@echo "$(WHITE)REMOVED EXECUTABLE FILE $(RESET)"

re: fclean all

.PHONY: all clean fclean re
