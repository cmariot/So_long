# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:55:54 by cmariot           #+#    #+#              #
#    Updated: 2021/09/13 13:16:18 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

EXECUTABLE_NAME = so_long

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

SRCS_DIR = srcs

SRCS = ${SRCS_DIR}/main.c \
	   ${SRCS_DIR}/check_extension.c \
	   ${SRCS_DIR}/parse_map.c \
	   ${SRCS_DIR}/check_map.c \
	   ${SRCS_DIR}/check_objects.c \
	   ${SRCS_DIR}/open_window.c \
	   ${SRCS_DIR}/display_images.c \
	   ${SRCS_DIR}/move_character.c \
	   ${SRCS_DIR}/libft/ft_itoa.c \
	   ${SRCS_DIR}/libft/gnl_without_bn.c \
	   ${SRCS_DIR}/libft/ft_putstr.c

SRCS_OBJS = ${SRCS:.c=.o}

MLX_INCLUDES_DIR = mlx_linux

MLX_LIBRARY_DIR = mlx_linux

MAP_NAME = ./maps/34x6.ber

REMOVE = rm -rf

GREEN = /bin/echo -e "\x1b[92m$1\x1b[0m"


.c.o:
				${COMPILER} ${COMPILER_FLAGS} -I${INCLUDES_DIR} -I${MLX_INCLUDES_DIR} -c $< -o ${<:.c=.o} -g

${NAME}:		compil_srcs

all: 			compil_srcs

bonus:			compil_srcs

norme:
				@norminette srcs includes
				@$(call GREEN,"The norm is checked.")

compil_srcs:	${SRCS_OBJS}
				@cd ${MLX_LIBRARY_DIR} && ./configure
				@${COMPILER} ${COMPILER_FLAGS} ${SRCS_OBJS} -Lmlx_linux -lmlx -lmlx_Linux -Imlx_linux -L/usr/lib -lXext -lX11 -lm -lz -o ${EXECUTABLE_NAME}  
				$(call GREEN,"The game is ready. Call the executable with a map as argument.")

test:			compil_srcs
				@./${EXECUTABLE_NAME} ${MAP_NAME}

leaks_macOs:			
				@make re
				@leaks -atExit -- ./${EXECUTABLE_NAME} ${MAP_NAME}

leaks_linux:
				@make re
				@valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes ./so_long maps/34x6.ber

clean:
				@${REMOVE} ${SRCS_OBJS}
				@$(call GREEN,"The object files have been deleted.")

fclean:			clean
				@${REMOVE} ${EXECUTABLE_NAME}
				@cd ${MLX_LIBRARY_DIR} && make clean
				@$(call GREEN,"The binary files have been deleted.")

re:				fclean all

.PHONY:			clean fclean
