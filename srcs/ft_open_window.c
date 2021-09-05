/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/05 18:09:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(t_window *window)
{
	free(window);
}

int	ft_red_cross(int key, void *window)
{
//	ft_free_all(window);
	window = 0;
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_close_window(int key, t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	mlx_destroy_window(window->mlx, window->win);
//	ft_free_all(window);
//	printf("ICI %s\n", window->map[0]);
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_key_pressed(int key, t_window *wind)
{
	if (key == 53)
		ft_close_window(key, wind);
	else if (key == 13)
		ft_move_forward(key, wind);
	else if (key == 0)
		ft_turn_left(key, wind);
	else if (key == 1)
		ft_move_back(key, wind);
	else if (key == 2)
		ft_turn_right(key, wind);
	ft_print_img(wind);
	return (0);
}

int	ft_open_window(t_window *wind)
{
	int			win_h;
	int			win_w;

	if (ft_check_map(wind) == -1)
		return (-1);
	wind->mlx = mlx_init();
	win_h = wind->obj.height * IMG_H;
	win_w = wind->obj.width * IMG_W;
	wind->win = mlx_new_window(wind->mlx, win_w, win_h, "./so_long");
	ft_xpm_to_img(wind);
	ft_print_img(wind);
	mlx_key_hook(wind->win, ft_key_pressed, wind);
	mlx_hook(wind->win, 17, 1L << 2, ft_red_cross, &wind);
	mlx_loop(wind->mlx);
	return (0);
}
