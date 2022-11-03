SOURCES = ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isdigit.c \
		 ft_isascii.c \
		 ft_isprint.c \
		 ft_strlen.c \
		 ft_toupper.c \
		 ft_tolower.c \
		ft_strrchr.c \
		ft_strchr.c \
	   ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_memset.c	\
	ft_bzero.c \
	ft_memcpy.c
FLAGS = -Wall -Wextra -Werror
HEADERS = libft.h
NAME = libft.a
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
