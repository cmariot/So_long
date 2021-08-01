/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/01 22:28:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_window(char **map, t_map *objects)
{
	void	*mlx_ptr;
	void	*win_ptr;

	printf("%s\n", *map);

	printf("WIDTH = %d\n", objects->width);
	printf("HEIGHT = %d\n", objects->height);
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (-1);
	win_ptr = mlx_new_window(mlx_ptr, objects->width * 100, objects->height * 100, "./so_long");
	mlx_loop(mlx_ptr);
	return (0);
}


/*int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "./so_long");
	mlx_loop(mlx_ptr);
	return (0);
}*/
