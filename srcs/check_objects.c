/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/09 14:55:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The height of the map = number of char * in the array */
int	count_array_height(char **array)
{
	int	i;
	int	height;

	i = 0;
	height = 0;
	while (array[i])
	{
		height++;
		i++;
	}
	return (height);
}

/* Set initial value of the objects structure */
void	struct_init(t_window *wind)
{
	wind->count = 0;
	wind->obj.height = count_array_height(wind->map);
	wind->obj.width = 0;
	wind->obj.start = 0;
	wind->obj.collected = 0;
	wind->obj.collectible = 0;
	wind->obj.exit = 0;
	wind->obj.wall = 0;
	wind->obj.space = 0;
	wind->obj.mvmt = 0;
}

/* Check if there is at least a Start, a Coin and an Exit */
int	check_objects(t_obj *objects)
{
	if (!objects->start)
	{
		ft_putstr("Error\nThere is no start on the map.\n");
		return (-1);
	}
	else if (!objects->collectible)
	{
		ft_putstr("Error\nThere is no collectible on the map.\n");
		return (-1);
	}
	else if (!objects->exit)
	{
		ft_putstr("Error\nThere is no  exit on the map.\n");
		return (-1);
	}
	else
		return (0);
}

/* The last 'P' will be the start position */
void	set_player_position(t_obj *objects, int x, int i)
{
	objects->player_y = i;
	objects->player_x = x;
	objects->start += 1;
}
