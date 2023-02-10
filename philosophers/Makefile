NAME = philo 
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
LIBFT = ./libft/libft.a
HEADERS = -I headers -I libft 


SOURCES = 	main.c \
			philo.c \
			parsing.c \
			utils.c

SRCBONUS = 
		

		

OBJS = ${addprefix sources/,${SOURCES:.c=.o}}
OBJBONUS = ${addprefix sources/,${SRCBONUS:.c=.o}}

all :  ${NAME}

.c.o: 
	gcc ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS} 
	make -C libft
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${LIB_MLX} ${HEADERS} -o ${NAME} 

bonus : ${OBJBONUS} 
	make -C libft
	gcc ${FLAGS} ${OBJBONUS} ${LIBFT} ${LIB_MLX} ${HEADERS} -o ${NAME} 

debug : ${OBJS} ${OBJBONUS} 
	make -C libft
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${LIB_MLX} ${HEADERS} -fsanitize=address -o ${NAME} 

clean :
	rm -f ${OBJS} ${OBJBONUS} 
	make clean -C libft

fclean : clean
	rm -f ${NAME} 
	make fclean -C libft

re : fclean all
