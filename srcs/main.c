/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 11:52:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* The so_long program takes a game map as argument.
 * The map need to have the ".ber" extension. */
int	main(int argc, char **argv)
{
	t_window	game;
	char		*map_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage : ./so_long [map.ber]\n", 2);
		return (EXIT_FAILURE);
	}
	map_name = argv[1];
	if (check_extension(map_name) == -1)
		exit(EXIT_FAILURE);
	else
	{
		game.map = store_map(map_name);
		check_map(&game);
		open_window(&game);
	}
	return (EXIT_SUCCESS);
}
