# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouly <amouly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:27:43 by llion             #+#    #+#              #
#    Updated: 2023/06/17 11:15:34 by amouly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= megaphone
CC			= g++
RM			= rm -rf
FLAGS		= -Wall -Werror -Wextra -g3 -std=c++98
MLX			= MLX42/build/libmlx42.a
HEADERS		= -Iinclude -Ilibft/include -L/Users/$(USER)/.brew/Cellar/glfw/3.3.8/lib -lglfw  \
			   -ldl -lglfw -lm
SRC			=	megaphone.cpp
					
OBJ			= $(addprefix obj/,$(notdir $(SRC:.cpp=.o)))

all:  $(NAME)

obj/%.o : src/%.cpp
	@mkdir -p obj
	@$(CC) -c $< -o $@

$(NAME) : $(OBJ) 
	@$(CC) $(FLAGS) $(OBJ)  -o $(NAME)	
	$(call echo,COMPILED,megaphone,32)

$(LIBFT): libft/Makefile
	@$(MAKE) -sC libft

libft/Makefile: libft/src/*.c libft/include/*.h
	@$(MAKE) -sC libft

debug: $(OBJ) 
	@$(CC) $(FLAGS) $(OBJ) $ $(HEADERS) -fsanitize=address -o $(NAME)	
	$(call echo,COMPILED,megaphone,33)

clean :
	@$(RM) $(OBJ)
	$(call echo,REMOVED,objects,31)

fclean : clean
	@$(RM) $(NAME) *.dSYM
	$(call echo,REMOVED,cub3d,31)

run:
	@./$(NAME)

re : fclean all

.PHONY : all clean fclean r libft/Makefile debug re
