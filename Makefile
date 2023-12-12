NAME = so_long
INC = /usr/include
INCLIB = $(INC)/../lib
LFLAGS = -L./libs/mlx -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
CC = gcc
SRCS = ./sources/*.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): minilibx libft
	$(CC) $(SRCS) -o $(NAME) $(LFLAGS) ./libs/mlx/libmlx.a ./libs/mlx/libmlx_Linux.a ./libs/libft/libft.a
minilibx:
	cd libs/mlx && ./configure && cd ../../
libft:
	cd libs/libft && make && cd ../../
clean:
	rm -rf $(OBJS)
	cd libs/mlx && ./configure clean && cd ../../
	cd libs/libft && make clean && cd ../../
fclean: clean
	rm -rf $(NAME)
	cd libs/libft && make fclean && cd ../../
re: fclean all
.PHONY: all clean fclean re libft minilibx