/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/07 11:26:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The so_long program takes a game map as argument.
 * The map need to have the ".ber" extension. */
int	main(int argc, char **argv)
{
	t_window	window;
	char		*map_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage : ./so_long [map.ber]\n", 2);
		return (EXIT_FAILURE);
	}
	map_name = argv[1]; 
	if (wrong_extension(map_name))
		exit(EXIT_FAILURE);
	else
	{
		window.map = store_the_map(map_name);
		if (window.map == NULL)
			exit(EXIT_FAILURE);
	}
	if (check_map(&window) == -1)
		exit(EXIT_FAILURE);
	open_window(&window);
	return (EXIT_SUCCESS);
}
