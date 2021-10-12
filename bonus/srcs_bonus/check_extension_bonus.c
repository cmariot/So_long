/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:37:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:32:37 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Check if the argument ends with ".ber" */
int	check_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] == '.')
		if (map_name[len - 3] == 'b')
			if (map_name[len - 2] == 'e')
				if (map_name[len - 1] == 'r')
					return (0);
	ft_putstr_fd("Error\nThe map has not the correct extension.\n", 2);
	return (-1);
}
