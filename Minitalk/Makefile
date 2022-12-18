### COMPILATION ###
CC = gcc
FLAGS = -Wall -Werror -Wextra




SOURCES = ft_printf.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		ft_putnbr_fd.c \
	   ft_putnbr_u_fd.c \
	   ft_putnbr_base.c \
	   ft_putpointer.c \
	   ft_count_num.c
FLAGS = -Wall -Wextra -Werror
HEADERS = ft_printf.h
NAME = libftprintf.a
OBJS = ${SOURCES:.c=.o}

all : ${NAME}

.c.o : 
	gcc ${FLAGS} -c $< -o ${<:.c=.o} 

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean :
	rm -f ${OBJS} 

fclean : clean
	rm -f ${NAME}

re : fclean all
