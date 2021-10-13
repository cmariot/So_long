/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:45:35 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 13:05:07 by cmariot          ###   ########.fr       */
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
		//if map x - 1 = 0
		//	move forward
		//else
		window->enemies[0].direction += 2;
	}
	if (window->enemies[0].direction == 4)
	{
		if (window->map[x - 1][y] == 0)
		{
			window->enemies[0].y--;
			window->map[x][y] = '0'; 
			window->map[x][y - 1] = '6';
		}
		else
			window->enemies[0].direction += 2;
	}
	if (window->enemies[0].direction == 6)
	{
		//if map x - 1 = 0
		//	move forward
		//else
			window->enemies[0].direction += 2;
	}
	if (window->enemies[0].direction == 8)
	{
		//if map x - 1 = 0
		//	move forward
		//else
			window->enemies[0].direction = 2;
	}
	printf("DATA ENEMY 1 :\n");
	printf("x = %d\n", window->enemies[0].x);
	printf("y = %d\n", window->enemies[0].y);
	printf("dir = %d\n", window->enemies[0].direction);
	//update_img
}
