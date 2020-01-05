NAME = fdf
CC = gcc
SRC_DIR = ./
OBJ_DIR = obj/
INC_DIRS = -I ./ -I /usr/local/include
INC_LIB = -L /usr/local/lib/
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SRCS = main.c figure_size.c hooks.c \
       	parser.c put_line.c record_color.c rotate.c \

OBJ = ${SRCS:c=o}

all: $(NAME)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INC_DIRS) -c -o $@ $^

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	@$(CC) $(INC_LIB) $(addprefix $(OBJ_DIR), $(OBJ)) $(INC_DIRS) $(FRAMEWORK) -o $(NAME)
	@echo "\033[38;2;139;20;39m A \033[38;2;190;60;0m L \033[38;2;255;156;0m L \
	\033[38;2;252;210;0m   D \033[38;2;60;160;50m O \033[38;2;32;80;250m N \033[38;2;200;8;250m E \033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[38;2;139;20;39m A \033[38;2;190;60;0m L \033[38;2;255;156;0m L \
	\033[38;2;252;210;0m   C \033[38;2;60;160;50m L \033[36m E \033[38;2;32;80;250m A \033[38;2;200;8;250m N \033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
