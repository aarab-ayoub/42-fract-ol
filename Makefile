NAME = fractol

SRC = src/main.c src/mandelbrot.c src/utils.c src/utils2.c src/events.c src/julia.c
SRCB = src/bonus/main_bonus.c src/bonus/burning_bonus.c src/bonus/utils_bonus.c src/bonus/events_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
MLX = -lmlx -framework OpenGL -framework AppKit
# CFLAGS = -Wall -Wextra -Werror -I includes -I minilibx-linux
# MLX = -L minilibx-linux -lmlx -lX11 -lXext -lm

# ANSI escape codes for styling
BOLD = \033[1m
RED = \033[35m
GREEN = \033[32m
RESET = \033[0m

# ASCII art for "FRACT'OL"
FRACTOL_ART = "\n\
$(RED)$(BOLD)███████╗██████╗  █████╗  ██████╗████████╗  ██   ██████╗ ██╗     $(RESET)\n\
$(RED)$(BOLD)██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝  █   ██╔═══██╗██║     $(RESET)\n\
$(RED)$(BOLD)█████╗  ██████╔╝███████║██║        ██║         ██║   ██║██║     $(RESET)\n\
$(RED)$(BOLD)██╔══╝  ██╔══██╗██╔══██║██║        ██║         ██║   ██║██║     $(RESET)\n\
$(RED)$(BOLD)██║     ██║  ██║██║  ██║╚██████╗   ██║         ╚██████╔╝███████╗$(RESET)\n\
$(RED)$(BOLD)╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝          ╚═════╝ ╚══════╝$(RESET)\n\
"

# Success message
SUCCESS_MSG = "$(GREEN)$(BOLD)✔ Successfully compiled $(NAME)!$(RESET)"
ayaarab = "$(RED)                                 created by : ayaarab √ [ESBG 💜]$(RESET)"

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(FRACTOL_ART)
	@echo $(ayaarab)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	@echo $(SUCCESS_MSG)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJB)
	@echo $(FRACTOL_ART)
	@$(CC) $(CFLAGS) $(SRCB) $(MLX) -o $(NAME)
	@echo $(SUCCESS_MSG)

clean:
	@rm -f $(OBJ) $(OBJB)
	@echo "$(GREEN)$(BOLD)✔ Cleaned object files!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)✔ Removed $(NAME)!$(RESET)"

re: fclean all

.PHONY: all clean fclean re