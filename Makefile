# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegreci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:45:50 by mdi-paol          #+#    #+#              #
#    Updated: 2023/07/03 17:42:40 by alegreci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft/libft.a
LIBMLX = mlx/libmlx.a
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
SRCS = main.c checker.c init_map.c updater.c input_manager.c texture_manager.c raycasting.c game_starter.c init_map2.c input_helper.c init_map3.c free_utils.c minimap.c mouse.c animation_manager.c check_map_manager.c check_map_helper.c minimap_helper.c
FLAGS = -Wall -Werror -Wextra
MFLAGS = -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
GNL_O = $(GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_O)
	@make -C libft
	@cc $(FLAGS) $(OBJS) $(LIBFT) $(GNL_O) $(MFLAGS) $(LIBMLX) -o $(NAME)
	@echo "\033[1;32m✅ Compiled ✅\033[0m"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean: libclean
	@rm -f $(OBJS) $(GNL_O)
	@echo "\033[1;34m☑️ Clean ☑️\033[0m"

libclean:
	@make clean -sC libft

fclean: clean libfclean
	@rm -f $(NAME)
	@echo "\033[1;34m☑️ Clean ☑️\033[0m"

libfclean:
	@make fclean -sC libft

re: fclean all

.PHONY: all lf clean libclean fclean libfclean re

.SILENT:
