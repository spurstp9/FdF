NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_INC = -I/usr/X11/include

MLX_FLAGS = -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

SRC_FOLDER = ./src/
SRC_FILES = altitude.c check.c display.c draw_utils.c free.c gradient.c key_hook.c main.c print_line_to_image.c\
projection.c rotation.c set_point_color.c shift.c zoom.c
SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ_FOLDER = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_FOLDER), $(OBJ_FILES))

HDR_FOLDER = ./inc/
HDR_FILES = fdf.h
HDR = $(addprefix $(HDR_FOLDER), $(HDR_FILES))

LIB_FOLDER = ./libft/
LIB_INC = ./libft/includes
LIB_FLAGS = -L $(LIB_FOLDER) -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_FOLDER)
	@gcc $(OBJ) $(MLX_FLAGS) $(LIB_FLAGS) -o $(NAME)

$(OBJ_FOLDER)%.o:$(SRC_FOLDER)%.c $(HDR)
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(CFLAGS) -I$(HDR_FOLDER) -I$(LIB_INC) $(MLX_INC) -c -o $@ $<

clean:
	@make -C $(LIB_FOLDER) clean
	@rm -rf $(OBJ) $(OBJ_FOLDER)

fclean: clean
	@make -C $(LIB_FOLDER) fclean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
