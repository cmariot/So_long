# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 18:55:54 by cmariot           #+#    #+#              #
#    Updated: 2021/08/02 20:52:55 by cmariot          ###   ########.fr        #
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
	   srcs/main.c

SRCS_OBJS = ${SRCS:.c=.o}

MLX_INCLUDE_DIR = mlx

MLX_LIBRARY_DIR = mlx

MAP_NAME = maps/map.ber

REMOVE = rm -rf

.c.o:
				${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} 
				
${NAME}:		compil_srcs

all: 			compil_srcs

bonus:			compil_srcs

norme:
				norminette srcs includes
				@printf "\x1b[32mThe norm is checked.\x1b[0m\n"

compil_srcs:	${SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} -I /usr/local/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit ${SRCS_OBJS} -o ${EXECUTABLE_NAME}  

				@printf "\x1b[32mThe game is ready. Call the executable with a map as argument.\x1b[0m\n"

test:			compil_srcs
				@./${EXECUTABLE_NAME} ${MAP_NAME}

leaks:			compil_srcs
				@leaks -atExit -- ./${EXECUTABLE_NAME}

clean:
				@${REMOVE} ${SRCS_OBJS}
				@printf "\x1b[32mThe object files have been deleted\x1b[0m\n"

fclean:			clean
				@${REMOVE} ${EXECUTABLE_NAME}
				@printf "\x1b[32mThe binary files have been deleted\x1b[0m\n"

re:				fclean all

.PHONY:			clean fclean
