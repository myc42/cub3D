# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 13:00:28 by macoulib          #+#    #+#              #
#    Updated: 2025/05/14 15:29:36 by macoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = libft.h
RM = rm -f


SRC = ft_atoi.c ft_bzero.c ft_calloc.c \
      ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
      ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
      ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
      ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
      ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
        ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

# Objets générés
OBJ = $(SRC:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)

# Règles par défaut
all: $(NAME)

# Création de la bibliothèque
$(NAME): $(OBJ) $(HEADER)
	ar -rcs $@ $^

# Ajout des bonus à la bibliothèque
bonus: $(OBJ) $(BONUSOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUSOBJ)

# Compilation des fichiers sources en objets
%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $^

# Suppression des objets
clean:
	$(RM) $(OBJ) $(BONUSOBJ)

# Suppression des objets et de la bibliothèque
fclean: clean
	$(RM) $(NAME)

# Recompilation complète
re: fclean all

.PHONY: all bonus clean fclean re