/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_macos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:23:18 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:35:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Exit if we close the window by clicking on the cross 
 * Leaks beacause no destroy_display() on macOS*/
int	close_window(t_window *window)
{
	free_map(window->map);
	free_img(window);
	free_img_pt2(window);
	mlx_destroy_window(window->mlx, window->win);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}
