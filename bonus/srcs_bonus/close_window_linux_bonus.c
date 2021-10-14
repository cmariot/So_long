/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_linux_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:22:16 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 12:15:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Exit if we close the window by clicking on the cross */
int	close_window(t_window *window)
{
	free_map(window->map);
	free_img(window);
	free_img_pt2(window);
	if (window->obj.enemy_count)
		free_enemy_list(&(window->enemies));
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}
