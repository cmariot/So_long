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

int	main(int argc, char **argv)
{
	t_window	window;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == -1)
			return (-1);
		window.map = parse_map(argv[1]);
		if (window.map == NULL)
			return (-1);
		if (check_the_map(&window) == -1)
			return (-1);
		open_window(&window);
	}
	else
		ft_putstr("Error\nUsage : ./so_long [MAP_PATH]\n");
	return (0);
}
