/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:37:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/08 16:33:34 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the argument name is "*.ber" */
int	check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] == '.')
	{
		if (map_name[len - 3] == 'b')
		{
			if (map_name[len - 2] == 'e')
			{
				if (map_name[len - 1] == 'r')
				{
					return (0);
				}
			}
		}
	}
	ft_putstr("Error\nThe map has not the correct extension.\n");
	return (-1);
}
