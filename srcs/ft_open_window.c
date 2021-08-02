/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/02 13:41:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_show_key(int key, void *window)
{
	window = 0;
	ft_putnbr(key);
	ft_putchar('\n');
	return (key);
}

int	ft_close_window(int key, t_window *window)
{
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_key_pressed(int key, void *window)
{
	if (key == 53)
		ft_close_window(key, window);
	else if (key == 13)
		ft_move_forward(key,window);
	else if (key == 0)
		ft_turn_left(key,window);
	else if (key == 1)
		ft_move_back(key,window);
	else if (key == 2)
		ft_turn_right(key,window);
	else
		ft_show_key(key, window);
	return (0);
}

int	ft_mvmt_count(int key, t_window *window)
{
	if (key == 0)
	{
		window->mvmt++;
		ft_putnbr(window->mvmt);
		ft_putchar('\n');
		return (0);
	}
	return (0);
}

int	ft_open_window(char **map, t_map *objects)
{
	t_window	window;

	printf("%s\n", *map);
	window.mvmt = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, objects->width * 100, objects->height * 100, "./so_long");
	//mlx_key_hook(window.win_ptr, ft_show_key, &window);
	//mlx_key_hook(window.win_ptr, ft_close_window, &window);
	mlx_hook(window.win_ptr, 02, 1L << 0, ft_key_pressed, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
