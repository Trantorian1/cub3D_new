NAME = cub3d

SRC_NAME = main_parsing.c \
		safe_fd_functions.c \
		parsing.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH 	= ./src
OBJ_PATH	= ./obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC = cc

DEBUG = -fsanitize=address,leak

CFLAGS = -Wall -Wextra -Werror -g -I./include -I./minilibx -I./libft

all : obj ${NAME}

obj :
	mkdir -p $(OBJ_PATH)

${NAME}: ${OBJ}
	make -C libft
	(cd minilibx && ./configure)
	$(CC) $(OBJ) -lX11 -lXext -I./minilibx -L./minilibx -lmlx -lm -o $(NAME) ./libft/libft.a

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	${CC} ${CFLAGS} -c $< -o $@

clean :
	rm -rf ${OBJ_PATH}
	make -C libft clean

fclean : clean
		rm -f ${NAME} *.a
		make -C libft clean

re : fclean all

.PHONY: re fclean clean all
