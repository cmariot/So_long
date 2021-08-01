/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/01 17:44:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_map_objects *map_objects)
{
	map_objects->start = 0;
	map_objects->collectible = 0;
	map_objects->exit = 0;
	map_objects->wall = 0;
	map_objects->space = 0;
}

int	ft_check_objects(t_map_objects *map_objects)
{
	if (!map_objects->start)
	{
		ft_putstr("Error\nThere is no start on the map.\n");
		return (-1);
	}
	else if (!map_objects->collectible)
	{
		ft_putstr("Error\nThere is no collectible on the map.\n");
		return (-1);
	}
	else if (!map_objects->exit)
	{
		ft_putstr("Error\nThere is no  exit on the map.\n");
		return (-1);
	}
	else
		return (0);
}
