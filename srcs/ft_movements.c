/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:41:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/05 17:43:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_finish(t_window *wind)
{
	if (wind->obj.collected / wind->obj.collectible == 1)
	{
		if (wind->obj.collected % wind->obj.collectible == 0)
		{
			exit(EXIT_SUCCESS);
		}
	}
	return (-1);
}

int	ft_move_forward(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x - 1][wind->obj.player_y] != '1')
	{
		wind->obj.mvmt++;
		wind->obj.player_x -= 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x + 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d\n", wind->obj.collected, wind->obj.collectible);
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
		{
			ft_finish(wind);
			wind->obj.player_x += 1;
		}
		else
		{
			wind->map[wind->obj.player_x + 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Top\n", wind->obj.mvmt);
	}
	return (key);
}

int	ft_turn_left(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x][wind->obj.player_y - 1] != '1')
	{
		wind->obj.mvmt++;
		wind->obj.player_y -= 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x][wind->obj.player_y + 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d\n", wind->obj.collected, wind->obj.collectible);
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
		{
			ft_finish(wind);
			wind->obj.player_y += 1;
		}
		else
		{
			wind->map[wind->obj.player_x][wind->obj.player_y + 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Left\n", wind->obj.mvmt);
	}
	return (key);
}

int	ft_move_back(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x + 1][wind->obj.player_y] != '1')
	{
		wind->obj.mvmt++;
		wind->obj.player_x += 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x - 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d\n", wind->obj.collected, wind->obj.collectible);
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
		{
			ft_finish(wind);
			wind->obj.player_x -= 1;
		}
		else
		{
			wind->map[wind->obj.player_x - 1][wind->obj.player_y] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Back\n", wind->obj.mvmt);
	}
	return (key);
}

int	ft_turn_right(int key, t_window *wind)
{
	if (wind->map[wind->obj.player_x][wind->obj.player_y + 1] != '1')
	{
		wind->obj.mvmt++;
		wind->obj.player_y += 1;
		if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'C')
		{
			wind->map[wind->obj.player_x][wind->obj.player_y - 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
			wind->obj.collected++;
			printf("%d/%d\n", wind->obj.collected, wind->obj.collectible);
		}
		else if (wind->map[wind->obj.player_x][wind->obj.player_y] == 'E')
		{
			ft_finish(wind);
			wind->obj.player_y -= 1;
		}
		else
		{
			wind->map[wind->obj.player_x][wind->obj.player_y - 1] = '0';
			wind->map[wind->obj.player_x][wind->obj.player_y] = 'P';
		}
		printf("Mouvement %d : Right\n", wind->obj.mvmt);
	}
	return (key);
}
