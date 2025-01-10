# Variables
NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
SRCS = srcs/main.c \
    #    srcs/render.c \
    #    srcs/hooks.c \
    #    srcs/fractals.c
OBJS = $(SRCS:.c=.o)
INCLUDES = -Iincludes -Imlx

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)

fclean: clean
	@echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

# Bonus Rules
bonus:
	@echo "Compiling bonus..."
	$(MAKE) BONUS=1

.PHONY: all clean fclean re bonus
