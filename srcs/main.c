/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 21:20:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
//	int		file_descriptor;
	char	**map;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == -1)
			return (-1);
		map = ft_parse_map(argv[1]);
		if (!map)
			return (-1);
		ft_check_map(map);
	}
	return (0);
}
