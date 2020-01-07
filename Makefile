NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_INC = -I/usr/X11/include

MLX_FLAGS = -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

SRC_FOLDER = ./src/
SRC_FILES = main.c print_line.c utils.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ_FOLDER = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))

HDR_FOLDER = ./inc/
HDR_FILES = fdf.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(MLX_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	mkdir -p $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -I$(HDR_FOLDER) $(MLX_INC) -c -o $@ $<

clean:
	rm -rf $(OBJ) $(OBJ_FOLDER)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
