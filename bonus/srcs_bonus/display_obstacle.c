/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_obstacle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:36:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 16:19:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_window *window)
{
	printf("Game over.\nIt was a trap.\n");
	close_window(window);
}

int	its_a_trap(t_window *window, char key)
{
	if (key == 'W' && window->obj.player_x != 1)
		game_over(window);
	else if (key == 'A' && window->obj.player_y != 1)
		game_over(window);
	else if (key == 'S' && window->obj.player_x != (window->obj.height - 2))
		game_over(window);
	else if (key == 'D' && window->obj.player_y != (window->obj.width - 2))
		game_over(window);
	return (0);
}

void	display_obstacle1(t_window *wind, int x, int y)
{
	if (wind->trap_count == 0)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap1.img, x, y);
	else if (wind->trap_count == 1)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	else if (wind->trap_count == 2)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap3.img, x, y);
	else if (wind->trap_count == 3)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	wind->count++;
}

void	display_obstacle2(t_window *wind, int x, int y)
{
	if (wind->trap_count == 0)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	else if (wind->trap_count == 1)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap3.img, x, y);
	else if (wind->trap_count == 2)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	else if (wind->trap_count == 3)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap1.img, x, y);
	wind->count++;
}

void	display_obstacle3(t_window *wind, int x, int y)
{
	if (wind->trap_count == 0)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap3.img, x, y);
	else if (wind->trap_count == 1)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	else if (wind->trap_count == 2)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap1.img, x, y);
	else if (wind->trap_count == 3)
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->trap2.img, x, y);
	wind->count = 0;
}
