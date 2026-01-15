NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -Iincludes

LIBFT_DIR   = librairie
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

OBJ_DIR     = obj

SRCS = \
	src/parsing/parsing_utils.c \
	src/parsing/parsing_utils1.c \
	src/parsing/parsing_utils2.c \
	src/parsing/parsing_utils3.c \
	src/parsing/parsing_utils4.c \
	src/parsing/texture_parsing.c \
	src/parsing/z_parsing.c \
	src/parsing/verif_load_xpm.c \
	src/parsing/get_next_line.c \
	src/parsing/color_ceiling_floor.c \
	src/parsing/stock_map.c \
	src/parsing/player_position.c \
	src/parsing/mlx_management.c \
	src/parsing/get_map_file.c \
	src/parsing/verif_map.c \
	src/parsing/verif_argv.c \
	src/parsing/init_map.c \
	src/parsing/z_parsing2.c \
	src/cub3D.c \
	src/game_loop.c \
	src/controls.c \
	src/render_frame.c \
	src/render_frame_utils.c \
	src/cleanup.c \
	src/rotation.c \
	src/parsing/Clean_map_header.c \
	src/minimap.c

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	

fclean: clean
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re
