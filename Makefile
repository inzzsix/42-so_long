SRCS = checks.c hooks.c init_and_launch_mlx.c utils2.c player_moves.c player.c read_and_validate_map.c render.c so_long.c utils.c
OBJS = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft
INCLUDES = -I/usr/include -Imlx -Iincludes -I./mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft/ft_libft/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/ft_libft/libft.a ${MLX_FLAGS}

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx || true
	make -C mlx
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./libft/ft_libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./libft/ft_libft/libft.a

re: fclean all

.PHONY: all clean fclean re