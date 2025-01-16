NAME = fractol

SRC = src/main.c src/mandelbrot.c src/utils.c src/utils2.c src/events.c src/julia.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
MLX = -lmlx -framework OpenGL -framework AppKit
# CFLAGS = -Wall -Wextra -Werror -I includes -I minilibx-linux
# MLX = -L minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re