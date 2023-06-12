# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdi-paol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:45:50 by mdi-paol          #+#    #+#              #
#    Updated: 2023/06/12 20:34:59 by mdi-paol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
LIBFT = libft/libft.a
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
SRC = main.c checker.c init_map.c init_map2.c init_map3.c free_utils.c
FLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : lf ps

lf:
	@make -sC libft
	@make bonus -sC libft

ps:
			gcc $(FLAGS) $(SRC) $(LIBFT) $(GNL) -o $(NAME)
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
