/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/05 17:39:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_window *wind)
{
	wind->obj.height = 0;
	wind->obj.width = 0;
	wind->obj.start = 0;
	wind->obj.collected = 0;
	wind->obj.collectible = 0;
	wind->obj.exit = 0;
	wind->obj.wall = 0;
	wind->obj.space = 0;
	wind->obj.mvmt = 0;
}

int	ft_check_objects(t_obj *objects)
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
