/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 18:17:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* MLX hook : if a key is pressed do action and print a new img */
int	key_pressed(int key, t_window *wind)
{
	if (key == ESC_KEY)
		close_window(wind);
	else if (key == W_KEY)
		move_forward(key, wind);
	else if (key == A_KEY)
		turn_left(key, wind);
	else if (key == S_KEY)
		move_back(key, wind);
	else if (key == D_KEY)
		turn_right(key, wind);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
	{
		background_color(wind, IMG_H * (wind->obj.height + 1),
			IMG_W * wind->obj.width);
		display_mouvement_count(wind);
		display_heart_count(wind);
	}
	return (0);
}

int	animation(t_window *window)
{
	if (window->frame < 20)
	{
		if (window->frame % 2 == 0)
			obstacle_animation(window);
		update_img(window);
		usleep(50000);
		window->frame++;
	}
	else
	{
		if (window->obj.enemy_count > 0)
			move_enemy(window);
		window->frame = 0;
	}
	return (0);
}

/* Set the mlx_ptr and create a window, mlx loop until exit() */
int	open_window(t_window *wind)
{
	int			win_h;
	int			win_w;

	get_enemy_data(wind);
	wind->mlx = mlx_init();
	win_h = (wind->obj.height + 1) * IMG_H;
	win_w = wind->obj.width * IMG_W;
	wind->win = mlx_new_window(wind->mlx, win_w, win_h, "./so_long_bonus");
	if (open_xpm_images(wind) == -1)
		close_window(wind);
	background_color(wind, win_h, win_w);
	print_img(wind);
	mlx_key_hook(wind->win, key_pressed, wind);
	mlx_hook(wind->win, 33, 1L << 5, close_window, wind);
	mlx_loop_hook(wind->mlx, animation, wind);
	mlx_loop(wind->mlx);
	return (0);
}
