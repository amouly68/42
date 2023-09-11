# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouly <amouly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:27:43 by llion             #+#    #+#              #
#    Updated: 2023/09/11 11:12:11 by amouly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= span
CC			= c++
RM			= rm -rf
CXXFLAGS	= -Wall -Werror -Wextra -g -g3 -std=c++98
HEADERS		= -I include 
SRC			=	main.cpp \
				Span.cpp
				
				
					
OBJ			= $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

all:  $(NAME)

obj/%.o : src/%.cpp
	mkdir -p obj
	$(CC) $(CXXFLAGS) $(HEADERS) -c $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $(CXXFLAGS) $(OBJ)  $(HEADERS) -o $(NAME)	

debug: $(OBJ) 
	$(CC) $(CXXFLAGS) $(OBJ) $(HEADERS) -fsanitize=address -o $(NAME)	

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME) *.dSYM

run:
	./$(NAME)

re : fclean all

.PHONY : all clean fclean r libft/Makefile debug re
