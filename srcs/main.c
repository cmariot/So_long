/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/05 17:59:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	window;
	int			i;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == -1)
			return (-1);
		window.map = ft_parse_map(argv[1]);
		if (window.map == NULL)
			return (-1);
		ft_open_window(&window);
		i = 0;
		while (window.map[i])
		{
			free(window.map[i]);
			i++;
		}
		free(window.map);
	}
	return (0);
}
