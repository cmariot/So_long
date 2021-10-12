/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 16:23:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:36:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Check if there is at least a Start, a Coin and an Exit */
int	check_objects(t_obj *objects)
{
	if (!objects->start)
	{
		ft_putstr_fd("Error\nThere is no start on the map.\n", 2);
		return (-1);
	}
	else if (!objects->collectible)
	{
		ft_putstr_fd("Error\nThere is no collectible on the map.\n", 2);
		return (-1);
	}
	else if (!objects->exit)
	{
		ft_putstr_fd("Error\nThere is no  exit on the map.\n", 2);
		return (-1);
	}
	else
		return (0);
}
