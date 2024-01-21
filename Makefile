# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 00:00:59 by epaksoy           #+#    #+#              #
#    Updated: 2024/01/21 09:36:49 by epaksoy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MLXCC = -Imlx -Llibs/mlx -lmlx
OPENGL = -framework OpenGL -framework AppKit
ALLIN	= $(MLXCC) $(OPENGL) libs/libft/libft.a libs/mlx/libmlx.a
CC = gcc -Wall -Wextra -Werror
SRCS = ./sources/*.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): minilibx libft
	$(CC) $(SRCS) -o $(NAME) $(ALLIN)
minilibx:
	cd libs/mlx && make 2> /dev/null && cd ../../
libft:
	cd libs/libft && make 2> /dev/null && cd ../../
clean:
	rm -rf $(OBJS)
	cd libs/mlx && make clean && cd ../../
	cd libs/libft && make clean && cd ../../
fclean: clean
	rm -rf $(NAME)
	cd libs/libft && make fclean && cd ../../
re: fclean all
.PHONY: all clean fclean re libft minilibx
