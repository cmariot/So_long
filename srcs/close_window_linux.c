/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_linux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:22:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 13:22:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Exit if we close the window by clicking on the cross */
int	close_window(t_window *window)
{
	free_map(window->map);
	free_img(window);
	free_img_pt2(window);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}
