# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicleena <nicleena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 15:26:57 by nicleena          #+#    #+#              #
#    Updated: 2024/09/27 13:45:39 by nicleena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long
CC =	gcc
CFLAGS =	-Wall -Werror -Wextra -g -fsanitize=address

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line/

SRC =	src/cleanup.c\
		src/loading_map.c\
		src/map_check.c\
		src/main.c\
		src/moves.c\
		src/parsing.c\
		src/parsing2.c\
		src/render.c\
		src/utils.c\
		src/sprites.c\
		$(GNL_DIR)/get_next_line.c\
		$(GNL_DIR)/get_next_line_utils.c\

OBJ =	$(SRC:.c=.o)

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	echo "\n✅ Compilation terminée: $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) 2>/dev/null

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re


