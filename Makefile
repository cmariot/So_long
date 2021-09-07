# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:55:54 by cmariot           #+#    #+#              #
#    Updated: 2021/09/06 13:06:30 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

EXECUTABLE_NAME = so_long

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

SRCS_DIR = srcs

SRCS = srcs/ft_check_extension.c \
	   srcs/ft_check_map.c\
	   srcs/ft_check_objects.c \
	   srcs/ft_map_parsing.c \
	   srcs/ft_putstr.c \
	   srcs/get_next_line.c \
	   srcs/get_next_line_utils.c \
	   srcs/ft_open_window.c \
	   srcs/ft_movements.c \
	   srcs/ft_images.c \
	   srcs/ft_player.c \
	   srcs/ft_itoa.c \
	   srcs/main.c

SRCS_OBJS = ${SRCS:.c=.o}

MLX_INCLUDES_DIR = mlx_linux

MLX_LIBRARY_DIR = mlx_linux

MAP_NAME = ./maps/34x6.ber

REMOVE = rm -rf

# COMPILATION
.c.o:
			${COMPILER} ${COMPILER_FLAGS} -I${INCLUDES_DIR} -I${MLX_INCLUDES_DIR} -c $< -o ${<:.c=.o}
				
${NAME}:		compil_srcs

all: 			compil_srcs

bonus:			compil_srcs

norme:
			@norminette srcs includes
			@printf "\x1b[32mThe norm is checked.\x1b[0m\n"

# EDITION LIENS
compil_srcs:		${SRCS_OBJS}
			@cd ${MLX_LIBRARY_DIR} && ./configure
			@${COMPILER} ${COMPILER_FLAGS} ${SRCS_OBJS} -Lmlx_linux -lmlx -lmlx_Linux -Imlx_linux -L/usr/lib -lXext -lX11 -lm -lz -o ${EXECUTABLE_NAME}  
			@printf "\x1b[32mThe game is ready. Call the executable with a map as argument.\x1b[0m\n"

test:			compil_srcs
			@./${EXECUTABLE_NAME} ${MAP_NAME}

leaks:			
			@make re
			@leaks -atExit -- ./${EXECUTABLE_NAME} ${MAP_NAME}

clean:
			@${REMOVE} ${SRCS_OBJS}
			@printf "\x1b[32mThe object files have been deleted\x1b[0m\n"

fclean:			clean
			@${REMOVE} ${EXECUTABLE_NAME}
			@cd ${MLX_LIBRARY_DIR} && make clean
			@printf "\x1b[32mThe binary files have been deleted\x1b[0m\n"

re:			fclean all

.PHONY:			clean fclean
