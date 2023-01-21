NAME = so_long 
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
SOURCES = ./sources
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
HEADERS = -I ./libft/libft.h -I so_long.h


SOURCES = parse_map.c \
			print.c \
			free.c \
			checkline.c \
			checklist.c \
			argerror.c \
			checktab.c \
			main.c

		

		

OBJS = ${SOURCES:.c=.o}

all :  ${LIBFT} ${NAME}

${LIBFT} : 
		make -C ${LIBFT_DIR}

.c.o: 
	gcc ${FLAGS} -c $< -o ${<:.c=.o}  

${NAME} : ${OBJS} 
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${HEADERS} -o ${NAME} 

debug : ${OBJS} 
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${HEADERS} -fsanitize=address -o ${NAME} 

clean :
	rm -f ${OBJS} 
	make -C ${LIBFT_DIR} clean

fclean : clean
	rm -f ${NAME} 
	make -C ${LIBFT_DIR} fclean

re : fclean all
