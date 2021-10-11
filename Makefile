# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2021/10/11 15:09:07 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME		= so_long
SRCS_DIR	= srcs
INCL_DIR	= includes
LIBFT_DIR	= libft
OBJS_DIR	= objs/

# Select the correct minilibX for the current system
# Works on macOS (ARM64) & Linux
UNAME := $(shell uname -m)
ifeq ($(UNAME), arm64)
	MLX = mlx_macos
else
	MLX = mlx_linux
endif

# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC					= gcc

CFLAGS				= -Wall -Wextra -Werror
CFLAGS				+= -I $(INCL_DIR)
CFLAGS				+= -I $(LIBFT_DIR)
CFLAGS				+= -I $(MLX)

LFLAGS				= -Wall -Wextra -Werror
LFLAGS_LIB			= -L libft -l ft
LFLAGS_LIB			+= -L $(MLX) -l mlx

UNAME := $(shell uname -m)
ifeq ($(UNAME), arm64)
	LFLAGS_LIB += -framework OpenGL -framework AppKit
	KEYMAP = -D ESC_KEY=53 -D W_KEY=13 -D S_KEY=1 -D D_KEY=2 -D A_KEY=0
else
	CFLAGS += -I /usr/include -O3
	LFLAGS_LIB += -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm 
	KEYMAP = -D ESC_KEY=65307 -D W_KEY=119 -D S_KEY=115 -D D_KEY=100 -D A_KEY=97
endif

# Debug flag, use with 'make DEBUG=1'
ifeq ($(DEBUG), 1)
	CFLAGS			+= -g3
	LFLAGS			+= -g3
endif



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS		= main.c \
			  check_extension.c \
			  check_map.c \
			  check_objects.c \
			  display_images.c \
			  move_character.c \
			  open_window.c \
			  colors.c \
			  update_img.c \
			  parse_map.c \
			  gnl_without_bn.c

SRC			:= $(notdir $(SRCS))

OBJ			:= $(SRC:.c=.o)

OBJS		:= $(addprefix $(OBJS_DIR), $(OBJ))

VPATH		:= $(SRCS_DIR) $(OBJS_DIR) $(shell find $(SRCS_DIR) -type d)


# **************************************************************************** #
#									COLORS                                     #
# **************************************************************************** #

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

all : $(NAME)

header :
	#	@figlet SoLong
		@echo

# Compiling
$(OBJS_DIR)%.o : %.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) $(KEYMAP) -c $< -o $@
		@printf "$(YE)$(CC) $(CFLAGS) $(KEYMAP) -c $< -o $@ ✅ \n$(RC)"

mlx_compil:
		@printf "$(YE)MinilibX compilation ... "
		@make -C $(MLX)
		@printf "Success !$(RC)\n\n"

libft_compil:
		@printf "$(YE)Libft compilation ... "
		@make -C libft
		@printf "Success !$(RC)\n\n"

srcs_compil :
		@printf "$(YE)Source code compilation ... \n$(RC)"
			
# Linking
$(NAME)	: header libft_compil mlx_compil srcs_compil $(SRCS) $(OBJS)
		@printf "$(YE)$(NAME) compilation success !\n\n$(RC)"
		@printf "$(GR)Object files linking ...\n$(CC) $(LFLAGS) $(OBJS) $(LFLAGS_LIB) $(RC)\n"
		@$(CC) $(LFLAGS) $(OBJS) $(LFLAGS_LIB) -o $(NAME)
		@printf "$(GR)Success !\n$(NAME) is ready.\n\n$(RC)"
		@printf "Usage :\n./so_long [MAP_NAME]\n"

bonus : $(NAME)

# Check 42 norm 
norm :
				@norminette srcs includes libft

lvl0:			${NAME}
				./so_long maps/min.ber

lvl1:			${NAME}
				./so_long maps/lvl1.ber
				
lvl2:			${NAME}
				./so_long maps/lvl2.ber

lvl3:			${NAME}
				./so_long maps/lvl3.ber

# Remove object files
clean :
		@printf "$(RE)Removing $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"
		@printf "Cleaning libft ... "
		@make clean -C libft
		@printf "Done\n"
		@printf "Cleaning MinilibX ... "
		@make clean -C $(MLX)
		@printf "Done$(RC)\n"

# Remove object and binary files
fclean : clean
		@printf "$(RE)Removing $(NAME) ... "
		@rm -f $(NAME)
		@printf "Done\n"
		@printf "Removing libft.a ... "
		@make fclean -C libft
		@printf "Done\n"
		@printf "Cleaning MinilibX ... "
		@make clean -C $(MLX)
		@printf "Done$(RC)\n"

# Remove all and recompile
re :	 fclean all

.PHONY : clean fclean
