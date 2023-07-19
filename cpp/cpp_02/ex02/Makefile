# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouly <amouly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:27:43 by llion             #+#    #+#              #
#    Updated: 2023/07/17 12:12:29 by amouly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= hi_this_is_brain
CC			= c++
RM			= rm -rf
CXXFLAGS	= -Wall -Werror -Wextra -g3 -std=c++98
HEADERS		= -I include 
SRC			=	main.cpp  
					
OBJ			= $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

all:  $(NAME)

obj/%.o : src/%.cpp
	mkdir -p obj
	$(CC) $(CXXFLAGS) $(HEADERS) -c $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $(CXXFLAGS) $(OBJ)  $(HEADERS) -o $(NAME)	

$(LIBFT): libft/Makefile
	$(MAKE) -sC libft

libft/Makefile: libft/src/*.c libft/include/*.h
	$(MAKE) -sC libft

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
