/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/08 16:29:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Exit if we close the window by clicking on the cross */
int	red_cross(int key, void *window)
{
	window = NULL;
	if (window == NULL)
		exit(EXIT_SUCCESS);
	return (key);
}

/* If ESC is pressed */
int	close_window(int key, t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
	return (key);
}

/* MLX hook : if a key is pressed do action */
int	key_pressed(int key, t_window *wind)
{
	if (key == ESC_KEY)
		close_window(key, wind);
	else if (key == W_KEY)
		move_forward(key, wind);
	else if (key == A_KEY)
		turn_left(key, wind);
	else if (key == S_KEY)
		move_back(key, wind);
	else if (key == D_KEY)
		turn_right(key, wind);
	print_img(wind);
	return (0);
}

/* Set the mlx_ptr and create a window, mlx loop until exit() */
int	open_window(t_window *wind)
{
	int			win_h;
	int			win_w;

	if (check_map(wind) == -1)
		return (-1);
	wind->mlx = mlx_init();
	win_h = wind->obj.height * IMG_H;
	win_w = wind->obj.width * IMG_W;
	wind->win = mlx_new_window(wind->mlx, win_w, win_h, "./so_long");
	open_xpm_img(wind);
	print_img(wind);
	mlx_key_hook(wind->win, key_pressed, wind);
	mlx_hook(wind->win, 17, 1L << 2, red_cross, &wind);
	mlx_loop(wind->mlx);
	return (0);
}
