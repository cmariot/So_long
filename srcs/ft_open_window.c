/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/04 18:30:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_red_cross(int key, void *window)
{
	(void)window;
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_close_window(int key, t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_key_pressed(int key, void *window)
{
	if (key == 53)
		ft_close_window(key, window);
	else if (key == 13)
		ft_move_forward(key, window);
	else if (key == 0)
		ft_turn_left(key, window);
	else if (key == 1)
		ft_move_back(key, window);
	else if (key == 2)
		ft_turn_right(key, window);
	return (0);
}

int	ft_open_window(char **map, t_obj *objects)
{
	t_window	wind;
	int			win_h;
	int			win_w;

	wind.mlx = mlx_init();
	win_h = objects->height * 40;
	win_w = objects->width * 40;
	wind.win = mlx_new_window(wind.mlx, win_w, win_h, "./so_long");
	ft_xpm_to_img(&wind);
	ft_print_img(wind, map, objects);
	mlx_key_hook(wind.win, ft_key_pressed, &wind);
	mlx_hook(wind.win, 17, 1L << 2, ft_red_cross, &wind);
	mlx_loop(wind.mlx);
	return (0);
}
