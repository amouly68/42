NAME = Minitalk
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
HEADERS = -I ./libft/libft.h


SOURCES = server.c 

OBJS = ${SOURCES:.c=.o}

all :  ${LIBFT} ${NAME}

${LIBFT} : 
		make -C ${LIBFT_DIR}

.c.o: 
	gcc ${FLAGS} -c $< -o ${<:.c=.o}  

${NAME} : ${OBJS}
	gcc ${FLAGS} ${OBJS} ${LIBFT} ${HEADERS} -o ${NAME} 

clean :
	rm -f ${OBJS} 
	make -C ${LIBFT_DIR} clean

fclean : clean
	rm -f ${NAME}
	make -C ${LIBFT_DIR} fclean

re : fclean all
