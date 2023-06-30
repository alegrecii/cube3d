# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:45:50 by mdi-paol          #+#    #+#              #
#    Updated: 2023/06/30 14:46:05 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
LIBFT = libft/libft.a
LIBMLX = mlx/libmlx.a
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
SRC = main.c checker.c init_map.c updater.c input_manager.c texture_manager.c raycasting.c game_starter.c init_map2.c input_helper.c init_map3.c free_utils.c minimap.c mouse.c animation_manager.c check_map_manager.c
FLAGS = -Wall -Werror -Wextra -g
MFLAGS = -lX11 -lXext -lm

all : $(NAME)

$(NAME) : lf ps

lf:
	@make -sC libft
	@make bonus -sC libft

ps:
			gcc $(FLAGS) $(SRC) $(LIBFT) $(LIBMLX) $(GNL) $(MFLAGS) -o $(NAME)
			@echo "\033[1;32m✅ Compiled ✅\033[0m"

clean :		libclean
			rm -rf
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libclean :
	@make clean -sC libft

fclean :	clean libfclean
			rm -rf $(NAME)
			@echo "\033[1;34m☑️  Clean ☑️\033[0m"

libfclean :
			@make fclean -sC libft

re : fclean all

.SILENT:
