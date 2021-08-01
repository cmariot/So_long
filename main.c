/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/01 17:44:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	**map;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == -1)
			return (-1);
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			ft_putstr("Error\nThe map couldn't be open. Check the path.\n");
			return (-1);
		}
		map = ft_save_map(file_descriptor, argv[1]);
		if (map == NULL)
		{
			free(map);
			return (-1);
		}
		close(file_descriptor);
		if (ft_check_map(map) != -1)
			ft_putstr("The map is ok, let's open the window !\n");
		free(map);
	}
	return (0);
}
