/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_enemy_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 09:00:53 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 09:22:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_enemy_images_pt2(t_window *w)
{
	int		iw;
	int		ih;

	w->enemy_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/enemy_left.xpm", &iw, &ih);
	if (w->enemy_left.img == NULL)
		return (-1);
	w->enemy_left.add = mlx_get_data_addr(w->enemy_left.img,
			&w->enemy_left.bpp, &w->enemy_left.len, &w->enemy_left.end);
	w->enemy_top.img = mlx_xpm_file_to_image(w->mlx,
			"./img/enemy_top.xpm", &iw, &ih);
	if (w->enemy_top.img == NULL)
		return (-1);
	w->enemy_top.add = mlx_get_data_addr(w->enemy_top.img,
			&w->enemy_top.bpp, &w->enemy_top.len, &w->enemy_top.end);
	return (0);
}

int	open_enemy_img(t_window *w)
{
	int		iw;
	int		ih;

	w->enemy_down.img = mlx_xpm_file_to_image(w->mlx,
			"./img/enemy_down.xpm", &iw, &ih);
	if (w->enemy_down.img == NULL)
		return (-1);
	w->enemy_down.add = mlx_get_data_addr(w->enemy_down.img,
			&w->enemy_down.bpp, &w->enemy_down.len, &w->enemy_down.end);
	w->enemy_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/enemy_right.xpm", &iw, &ih);
	if (w->enemy_right.img == NULL)
		return (-1);
	w->enemy_right.add = mlx_get_data_addr(w->enemy_right.img,
			&w->enemy_right.bpp, &w->enemy_right.len, &w->enemy_right.end);
	if (open_enemy_images_pt2(w) == -1)
		return (-1);
	return (0);
}
