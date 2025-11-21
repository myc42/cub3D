# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 21:42:46 by macoulib          #+#    #+#              #
#    Updated: 2025/11/21 19:44:56 by macoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d


CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -Iincludes

LIBFT_DIR   = librairie/
LIBFT       = $(LIBFT_DIR)/libft.a

LDFLAGS     = -L$(LIBFT_DIR)
LDLIBS      = -lft -lreadline -lncurses -ltinfo

OBJ_DIR     = obj

SRCS = \
	src/parsing/parsing_utils.c \
	src/parsing/get_next_line.c \
	src/parsing/stock_map.c \
	src/parsing/verif_map.c \
	src/cub3D.c 

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)



re: fclean all
	
.PHONY: all clean fclean re