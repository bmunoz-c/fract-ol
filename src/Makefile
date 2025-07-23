#_____Program name_____#
NAME		=	fractol

#_____Sources_____#
SRC			=	check_args.c init.c render.c events.c \
				utils.c bonus_burningship.c \
				main.c \

SRCS		=	$(addprefix $(SRC_DIR), $(SRC))

#_____Colors_____#
DEF_COLOR	=	\033[1;39m
WHITE_BOLD	=	\033[1m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CIAN		=	\033[1;36m

#_____#Directories_____#
BIN_DIR		=	bin/
SRC_DIR		=	src/
MLX_DIR		=	include/minilibx-linux/
LIBFT_DIR	=	include/libft/


#_____Objects_____#
OBJ			=	$(SRC:.c=.o) # $(SRC:%.c=$(BIN_DIR)%.o)
OBJS		=	$(addprefix $(BIN_DIR), $(OBJ))


#_____Minilibx_____#
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_DIR)$(MLX_NAME)

#_____Libft_____#
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)$(LIBFT_NAME)

#_____Includes_____#
INC			=	-I ./include/\
				-I $(LIBFT_DIR)\
				-I $(MLX_DIR)

#_____Compiler_____#
CC			=	gcc
CFLAGS		=	-Werror -Wextra -Wall
RM			=	rm -f

#_____Targets_____#
all: $(MLX) $(LIBFT) $(NAME)

$(BIN_DIR)%.o: $(SRC_DIR)%.c $(LIBFT)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(BIN_DIR)

$(BIN_DIR):
	@mkdir $(BIN_DIR)
#	@mkdir $(BIN_DIR)fractal_sets/
#	@mkdir $(BIN_DIR)color_schemes/

$(MLX):
	@echo "___________________________________"
	@echo "\n$(YELLOW)Making MiniLibX...$(DEF_COLOR)\n"
	@make -sC $(MLX_DIR)

$(LIBFT):
	@echo "___________________________________"
	@echo "\n$(YELLOW)Making libft...$(DEF_COLOR)\n"
	@make -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(OBJS)
	@echo "___________________________________"
	@echo "\n$(YELLOW)Compiling fractol...$(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "$(GREEN)Fractol ready.$(DEF_COLOR)\n"
	@echo "___________________________________"

$(BIN_DIR)%.o: %.c Makefile
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "$(WHITE_BOLD)Object$(YELLOW) $@ $(GREEN)compiled!$(DEF_COLOR)"

bonus: all

clean:
#	@$(RM) -rf $(BIN_DIR)
	@echo "Removing .o object files..."
	@rm -rf $(BIN_DIR)
	@make clean -C $(MLX_DIR) --no-print-directory
	@make fclean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
#	@$(RM) -r $(BIN_DIR)
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(MLX)
