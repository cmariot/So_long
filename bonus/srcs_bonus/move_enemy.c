/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:45:35 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 16:46:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_window *window, int x, int y)
{
	if (window->map[x + 1][y] == '0')
	{
		window->enemies[0].x += 1;
		window->map[x][y] = '0';
		window->map[x + 1][y] = '2';
	}
	else if (window->map[x + 1][y] == 'P' || window->map[x + 1][y] == 'Q' ||
			window->map[x + 1][y] == 'R' || window->map[x + 1][y] == 'S')
	{
		attack(window);
	}
	else
	{
		window->enemies[0].direction = 6;
		window->map[x][y] = '6';
	}
}

void	move_down(t_window *window, int x, int y)
{
	if (window->map[x - 1][y] == '0')
	{
		window->enemies[0].x -= 1;
		window->map[x][y] = '0';
		window->map[x - 1][y] = '8';
	}
	else if (window->map[x - 1][y] == 'P' || window->map[x - 1][y] == 'Q' ||
			window->map[x - 1][y] == 'R' || window->map[x - 1][y] == 'S')
	{
		attack(window);
	}
	else
	{
		window->enemies[0].direction = 4 ;
		window->map[x][y] = '4';
	}
}

void	move_left(t_window *window, int x, int y)
{
	if (window->map[x][y + 1] == '0')
	{
		window->enemies[0].y += 1;
		window->map[x][y] = '0';
		window->map[x][y + 1] = '6';
	}
	else if (window->map[x][y + 1] == 'P' || window->map[x][y + 1] == 'Q' ||
			window->map[x][y + 1] == 'R' || window->map[x][y + 1] == 'S')
	{
		attack(window);
	}
	else
	{
		window->enemies[0].direction = 8;
		window->map[x][y] = '8';
	}
}

void	move_right(t_window *window, int x, int y)
{
	if (window->map[x][y - 1] == '0')
	{
		window->enemies[0].y -= 1;
		window->map[x][y] = '0';
		window->map[x][y - 1] = '4';
	}
	else if (window->map[x][y - 1] == 'P' || window->map[x][y - 1] == 'Q' ||
			window->map[x][y - 1] == 'R' || window->map[x][y - 1] == 'S')
	{
		attack(window);
	}
	else
	{
		window->enemies[0].direction = 2;
		window->map[x][y] = '2';
	}
}

void	move_enemy(t_window *window)
{
	int	x;
	int	y;

	x = window->enemies[0].x;
	y = window->enemies[0].y;
	if (window->enemies[0].direction == 2)
	{
		move_up(window, x, y);
	}
	else if (window->enemies[0].direction == 4)
	{
		move_right(window, x, y);
	}
	else if (window->enemies[0].direction == 6)
	{
		move_left(window, x, y);
	}
	else if (window->enemies[0].direction == 8)
	{
		move_down(window, x, y);
	}
	update_img(window);
}
