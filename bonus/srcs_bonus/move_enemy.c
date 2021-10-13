/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:45:35 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 15:08:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_window *window)
{
	int	x;
	int y;

	x = window->enemies[0].x;
	y = window->enemies[0].y;
	if (window->enemies[0].direction == 2)
	{
		if (window->map[x + 1][y] == '0')
		{
			window->enemies[0].x += 1;
			window->map[x][y] = '0'; 
			window->map[x + 1][y] = '2';
		}
		else
		{
			window->enemies[0].direction += 2;
			window->map[x][y] = '4'; 
		}
	}
	else if (window->enemies[0].direction == 4)
	{
		if (window->map[x][y - 1] == '0')
		{
			window->enemies[0].y -= 1;
			window->map[x][y] = '0'; 
			window->map[x][y - 1] = '4';
		}
		else
		{
			window->enemies[0].direction += 2;
			window->map[x][y] = '4'; 
		}
	}
	else if (window->enemies[0].direction == 6)
	{
		if (window->map[x][y + 1] == '0')
		{
			window->enemies[0].y += 1;
			window->map[x][y] = '0'; 
			window->map[x][y + 1] = '6';
		}
		else
		{
			window->enemies[0].direction += 2;
			window->map[x][y] = '6'; 
		}
	}
	else if (window->enemies[0].direction == 8)
	{
		if (window->map[x - 1][y] == '0')
		{
			window->enemies[0].x -= 1;
			window->map[x][y] = '0'; 
			window->map[x - 1][y] = '8';
		}
		else
		{
			window->enemies[0].direction = 2;
			window->map[x][y] = '8'; 
		}
	}
	update_img(window);
}
