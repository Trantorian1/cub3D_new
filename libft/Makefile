NAME = libft.a 

SRC	= ft_strlen.c \
		ft_strnchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strjoin_n.c \
		ft_strjoin_and_free.c \
		get_next_line.c \

OBJS = ${SRC:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

${NAME}:
	${CC} ${CFLAGS} ${SRC}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all : ${NAME}

clean : 
	rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -f ${NAME} 

re : fclean all

.PHONY: re fclean clean bonus all
