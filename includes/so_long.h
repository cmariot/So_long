/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/08 14:59:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"

# define IMG_H 40
# define IMG_W 40
# define INT_MAX 2147483647

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97

typedef struct s_obj
{
	int	height;
	int	width;
	int	start;
	int	collected;
	int	collectible;
	int	exit;
	int	wall;
	int	space;
	int	mvmt;
	int	player_x;
	int	player_y;
}	t_obj;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct s_window
{
	char	**map;
	void	*mlx;
	void	*win;
	int		count;
	int		trap_count;
	t_obj	obj;
	t_img	ground1;
	t_img	ground2;
	t_img	ground3;
	t_img	wall_top1;
	t_img	wall_top2;
	t_img	wall_top3;
	t_img	wall_top_corner_left;
	t_img	wall_top_corner_right;
	t_img	wall_bottom_corner_left;
	t_img	wall_bottom_corner_right;
	t_img	wall_left;
	t_img	wall_right;
	t_img	wall_bottom;
	t_img	trap1;
	t_img	trap2;
	t_img	trap3;
	t_img	char_down;
	t_img	char_left;
	t_img	char_right;
	t_img	char_top;
	t_img	heart;
	t_img	exit;
}	t_window;

// SO LONG
int		check_extension(char *map_name);
char	**parse_map(char *map_path);
int		check_map(t_window *wind);
int		is_rectangular(char **map, int i);
void	struct_init(t_window *window);
int		check_objects(t_obj *objects);
int		check_the_map(t_window *window);
void	set_player_position(t_obj *objects, int x, int i);
int		open_window(t_window *window);
void	open_xpm_img(t_window *w);
void	put_img_to_window(char pos, t_window *wind, int x, int y);
void	print_img(t_window *wind);
int		move_forward(int key, t_window *wind);
int		turn_left(int key, t_window *wind);
int		move_back(int key, t_window *wind);
int		turn_right(int key, t_window *wind);
void	free_map(char **map);
int		close_window(int key, t_window *window);
char	*gnl_without_bn(int fd);
void	ft_putstr(char *str);
void	background_color(t_window *wind, int height, int width);
void	display_rules(t_window *window);

#endif
