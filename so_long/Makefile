NAME = so_long 
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
LIB_MLX =  /Users/$$USER/Documents/42cursus/42/mlx/libmlx42.a -lglfw -L /Users/$$USER/.brew/opt/glfw/lib

LIBFT = ./libft/libft.a
HEADERS = -I headers -I libft -I /Users/$$USER/Documents/42cursus/42/mlx/include/MLX42/


SOURCES = parse_map.c \
			print.c \
			free.c \
			checkline.c \
			checklist.c \
			argerror.c \
			checktab.c \
			add_graphic.c \
			flood_fill.c \
			controls_player.c \
			main.c

SRCBONUS = parse_map.c \
			print.c \
			free.c \
			checkline_bonus.c \
			checklist.c \
			argerror.c \
			checktab.c \
			add_graphic.c \
			flood_fill.c \
			controls_player.c \
			main.c
		

		

OBJS = ${addprefix sources/,${SOURCES:.c=.o}}
OBJBONUS = ${addprefix sources/,${SRCBONUS:.c=.o}}

all :  ${NAME}

.c.o: 
	gcc ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS} 
	make -C libft
	make -C /Users/$$USER/Documents/42cursus/42/mlx
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${LIB_MLX} ${HEADERS} -o ${NAME} 

bonus : ${OBJBONUS} 
	make -C libft
	make -C /Users/$$USER/Documents/42cursus/42/mlx
	gcc ${FLAGS} ${OBJBONUS} ${LIBFT} ${LIB_MLX} ${HEADERS} -o ${NAME} 

debug : ${OBJS} ${OBJBONUS} 
	make -C libft
	make -C /Users/$$USER/Documents/42cursus/42/mlx
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${LIB_MLX} ${HEADERS} -fsanitize=address -o ${NAME} 

clean :
	rm -f ${OBJS} ${OBJBONUS} 
	make clean -C libft
	make clean -C /Users/$$USER/Documents/42cursus/42/mlx

fclean : clean
	rm -f ${NAME} 
	make fclean -C libft
	make fclean -C /Users/$$USER/Documents/42cursus/42/mlx

re : fclean all
