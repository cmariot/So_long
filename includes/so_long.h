/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 17:48:13 by cmariot          ###   ########.fr       */
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
int		main(int argc, char **argv);
int		check_extension(char *map_name);
char	**store_map(char *map_path);
char	*gnl_without_bn(int fd);
int		check_map(t_window *wind);
void	init_structure(t_window *window);
int		check_objects(t_obj *objects);
void	set_player_position(t_obj *objects, int x, int i);
int		open_window(t_window *window);
int		open_xpm_images(t_window *w);
int		open_wall_img(t_window *w);
int		open_wall_corner_img(t_window *w);
void	print_img(t_window *wind);
void	display_character(t_window *wind, int x, int y, char pos);
void	display_heart(t_window*wind, int x, int y);
void	display_obstacle1(t_window *wind, int x, int y);
void	display_obstacle2(t_window *wind, int x, int y);
void	display_obstacle3(t_window *wind, int x, int y);
void	display_ground(t_window *wind, int x, int y);
void	display_wall(t_window *wind, int x, int y);
void	background_color(t_window *wind, int height, int width);
void	display_rules(t_window *wind);
void	display_heart_count(t_window *wind);
void	display_mouvement_count(t_window *wind);
int		move_forward(int key, t_window *wind);
int		turn_left(int key, t_window *wind);
int		move_back(int key, t_window *wind);
int		turn_right(int key, t_window *wind);
void	update_img(t_window *window);
int		its_a_trap(t_window *window, char key);
void	free_map(char **map);
void	free_img(t_window *window);
void	free_img_pt2(t_window *window);
int		close_window(t_window *window);

#endif
