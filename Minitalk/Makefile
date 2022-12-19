NAME = Minitalk
CLIENT = client
SERVER = server
CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
HEADERS = -I ./libft/libft.h


SOURCES_CL = client.c
SOURCES_SE = server.c


OBJS_CL = ${SOURCES_CL:.c=.o}
OBJS_SE = ${SOURCES_SE:.c=.o}

all :  ${LIBFT} ${NAME}

${LIBFT} : 
		make -C ${LIBFT_DIR}

.c.o: 
	gcc ${FLAGS} -c $< -o ${<:.c=.o}  

${NAME} : ${OBJS_CL} ${OBJS_SE}
	gcc ${FLAGS} ${OBJS_CL} ${LIBFT} ${HEADERS} -o ${CLIENT} 
	gcc ${FLAGS} ${OBJS_SE} ${LIBFT} ${HEADERS} -o ${SERVER}

clean :
	rm -f ${OBJS_CL} ${OBJS_SE} 
	make -C ${LIBFT_DIR} clean

fclean : clean
	rm -f ${CLIENT} ${SERVER} 
	make -C ${LIBFT_DIR} fclean

re : fclean all
