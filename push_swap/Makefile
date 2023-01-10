NAME = push_swap 
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
HEADERS = -I ./libft/libft.h -I push_swap.h


SOURCES = push_swap.c \
		fill_list.c \
		push.c \
		reverse.c \
		rotate.c \
		swap.c \
		check_error.c \
		up_to_fifteen.c \
		print_list.c \
		find_max_min.c \
		max_min_to_top.c \
		more_than_fifteen.c \
		a_to_b.c \
		a_to_b_v2.c
		

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
