/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 21:44:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize(t_obj *objects)
{
	objects->height = 0;
	objects->width = 0;
	objects->start = 0;
	objects->collectible = 0;
	objects->exit = 0;
	objects->wall = 0;
	objects->space = 0;
	objects->mvmt = 0;
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
