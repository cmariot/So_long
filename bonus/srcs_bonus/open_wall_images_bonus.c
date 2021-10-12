/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wall_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:35:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_wall_top_img(t_window *w)
{
	int		iw;
	int		ih;

	w->wall_top1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top1.xpm", &iw, &ih);
	if (w->ground3.img == NULL)
		return (-1);
	w->wall_top1.add = mlx_get_data_addr(w->wall_top1.img,
			&w->wall_top1.bpp, &w->wall_top1.len, &w->wall_top1.end);
	w->wall_top2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top2.xpm", &iw, &ih);
	if (w->wall_top2.img == NULL)
		return (-1);
	w->wall_top2.add = mlx_get_data_addr(w->wall_top2.img,
			&w->wall_top2.bpp, &w->wall_top2.len, &w->wall_top2.end);
	w->wall_top3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top3.xpm", &iw, &ih);
	if (w->wall_top3.img == NULL)
		return (-1);
	w->wall_top3.add = mlx_get_data_addr(w->wall_top3.img,
			&w->wall_top3.bpp, &w->wall_top3.len, &w->wall_top3.end);
	return (0);
}

int	open_wall_img(t_window *w)
{
	int		iw;
	int		ih;

	if (open_wall_top_img(w) == -1)
		return (-1);
	w->wall_bottom.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom.xpm", &iw, &ih);
	if (w->wall_bottom.img == NULL)
		return (-1);
	w->wall_bottom.add = mlx_get_data_addr(w->wall_bottom.img,
			&w->wall_bottom.bpp, &w->wall_bottom.len, &w->wall_bottom.end);
	w->wall_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_right.xpm", &iw, &ih);
	if (w->wall_right.img == NULL)
		return (-1);
	w->wall_right.add = mlx_get_data_addr(w->wall_right.img,
			&w->wall_right.bpp, &w->wall_right.len, &w->wall_right.end);
	w->wall_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_left.xpm", &iw, &ih);
	if (w->wall_left.img == NULL)
		return (-1);
	w->wall_left.add = mlx_get_data_addr(w->wall_left.img,
			&w->wall_left.bpp, &w->wall_left.len, &w->wall_left.end);
	return (0);
}

int	open_wall_corner_img_pt2(t_window *w)
{
	int		iw;
	int		ih;

	w->wall_bottom_corner_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom_corner_right.xpm", &iw, &ih);
	if (w->wall_bottom_corner_right.img == NULL)
		return (-1);
	w->wall_bottom_corner_right.add = mlx_get_data_addr(
			w->wall_bottom_corner_right.img, &w->wall_bottom_corner_right.bpp,
			&w->wall_bottom_corner_right.len, &w->wall_bottom_corner_right.end);
	w->wall_bottom_corner_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom_corner_left.xpm", &iw, &ih);
	if (w->wall_bottom_corner_left.img == NULL)
		return (-1);
	w->wall_bottom_corner_left.add = mlx_get_data_addr(
			w->wall_bottom_corner_left.img, &w->wall_bottom_corner_left.bpp,
			&w->wall_bottom_corner_left.len, &w->wall_bottom_corner_left.end);
	return (0);
}

int	open_wall_corner_img(t_window *w)
{
	int		iw;
	int		ih;

	w->wall_top_corner_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top_corner_right.xpm", &iw, &ih);
	if (w->wall_top_corner_right.img == NULL)
		return (-1);
	w->wall_top_corner_right.add = mlx_get_data_addr(
			w->wall_top_corner_right.img, &w->wall_top_corner_right.bpp,
			&w->wall_top_corner_right.len, &w->wall_top_corner_right.end);
	w->wall_top_corner_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top_corner_left.xpm", &iw, &ih);
	if (w->wall_top_corner_left.img == NULL)
		return (-1);
	w->wall_top_corner_left.add = mlx_get_data_addr(w->wall_top_corner_left.img,
			&w->wall_top_corner_left.bpp, &w->wall_top_corner_left.len,
			&w->wall_top_corner_left.end);
	if (open_wall_corner_img_pt2(w) == -1)
		return (-1);
	return (0);
}
