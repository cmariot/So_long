/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/08 23:48:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Exit if we close the window by clicking on the cross */
int	red_cross(int key, t_window **window)
{
	//It doesm't work ...
	close_window(key, *window);
	return (key);
}

/* If ESC is pressed */
int	close_window(int key, t_window *window)
{
	free_map(window->map);
	mlx_destroy_image(window->mlx, window->background.img);
	mlx_destroy_image(window->mlx, window->ground1.img);
	mlx_destroy_image(window->mlx, window->ground2.img);
	mlx_destroy_image(window->mlx, window->ground3.img);
	mlx_destroy_image(window->mlx, window->wall_top1.img);
	mlx_destroy_image(window->mlx, window->wall_top2.img);
	mlx_destroy_image(window->mlx, window->wall_top3.img);
	mlx_destroy_image(window->mlx, window->wall_top_corner_right.img);
	mlx_destroy_image(window->mlx, window->wall_top_corner_left.img);
	mlx_destroy_image(window->mlx, window->wall_bottom_corner_right.img);
	mlx_destroy_image(window->mlx, window->wall_bottom_corner_left.img);
	mlx_destroy_image(window->mlx, window->wall_bottom.img);
	mlx_destroy_image(window->mlx, window->wall_right.img);
	mlx_destroy_image(window->mlx, window->wall_left.img);
	mlx_destroy_image(window->mlx, window->trap1.img);
	mlx_destroy_image(window->mlx, window->trap2.img);
	mlx_destroy_image(window->mlx, window->trap3.img);
	mlx_destroy_image(window->mlx, window->heart.img);
	mlx_destroy_image(window->mlx, window->exit.img);
	mlx_destroy_image(window->mlx, window->char_top.img);
	mlx_destroy_image(window->mlx, window->char_left.img);
	mlx_destroy_image(window->mlx, window->char_right.img);
	mlx_destroy_image(window->mlx, window->char_down.img);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (key);
}

/* MLX hook : if a key is pressed do action */
int	key_pressed(int key, t_window *wind)
{
	if (key == ESC_KEY)
		close_window(key, (t_window *)wind);
	else if (key == W_KEY)
		move_forward(key, wind);
	else if (key == A_KEY)
		turn_left(key, wind);
	else if (key == S_KEY)
		move_back(key, wind);
	else if (key == D_KEY)
		turn_right(key, wind);
	wind->trap_count++;
	if (wind->trap_count > 3)
		wind->trap_count = 0;
	print_img(wind);
	return (0);
}

/* Set the mlx_ptr and create a window, mlx loop until exit() */
int	open_window(t_window *wind)
{
	int			win_h;
	int			win_w;

	wind->mlx = mlx_init();
	win_h = (wind->obj.height + 1) * IMG_H;
	win_w = wind->obj.width * IMG_W;
	wind->win = mlx_new_window(wind->mlx, win_w, win_h, "./so_long");
	open_xpm_img(wind);
	background_color(wind, win_h, win_w);
	display_rules(wind);
	print_img(wind);
	mlx_key_hook(wind->win, key_pressed, wind);
	mlx_hook(wind->win, 17, 1L << 2, close_window, (t_window *)wind);
	mlx_loop(wind->mlx);
	return (0);
}
