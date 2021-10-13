/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 09:12:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_ground_img(t_window *w)
{
	int		iw;
	int		ih;

	w->ground1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground1.xpm", &iw, &ih);
	if (w->ground1.img == NULL)
		return (-1);
	w->ground1.add = mlx_get_data_addr(w->ground1.img,
			&w->ground1.bpp, &w->ground1.len, &w->ground1.end);
	w->ground2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground2.xpm", &iw, &ih);
	if (w->ground2.img == NULL)
		return (-1);
	w->ground2.add = mlx_get_data_addr(w->ground2.img,
			&w->ground2.bpp, &w->ground2.len, &w->ground2.end);
	w->ground3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground3.xpm", &iw, &ih);
	if (w->ground3.img == NULL)
		return (-1);
	w->ground3.add = mlx_get_data_addr(w->ground3.img,
			&w->ground3.bpp, &w->ground3.len, &w->ground3.end);
	return (0);
}

int	open_char_img(t_window *w)
{
	int		iw;
	int		ih;

	w->char_down.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_down.xpm", &iw, &ih);
	if (w->char_down.img == NULL)
		return (-1);
	w->char_down.add = mlx_get_data_addr(w->char_down.img,
			&w->char_down.bpp, &w->char_down.len, &w->char_down.end);
	w->char_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_left.xpm", &iw, &ih);
	if (w->char_left.img == NULL)
		return (-1);
	w->char_left.add = mlx_get_data_addr(w->char_left.img,
			&w->char_left.bpp, &w->char_left.len, &w->char_left.end);
	w->char_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_right.xpm", &iw, &ih);
	if (w->char_right.img == NULL)
		return (-1);
	w->char_right.add = mlx_get_data_addr(w->char_right.img,
			&w->char_right.bpp, &w->char_right.len, &w->char_right.end);
	return (0);
}

int	open_trap_img(t_window *w)
{
	int		iw;
	int		ih;

	w->trap1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap1.xpm", &iw, &ih);
	if (w->trap1.img == NULL)
		return (-1);
	w->trap1.add = mlx_get_data_addr(w->trap1.img,
			&w->trap1.bpp, &w->trap1.len, &w->trap1.end);
	w->trap2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap2.xpm", &iw, &ih);
	if (w->trap2.img == NULL)
		return (-1);
	w->trap2.add = mlx_get_data_addr(w->trap2.img,
			&w->trap2.bpp, &w->trap2.len, &w->trap2.end);
	w->trap3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap3.xpm", &iw, &ih);
	if (w->trap3.img == NULL)
		return (-1);
	w->trap3.add = mlx_get_data_addr(w->trap3.img,
			&w->trap3.bpp, &w->trap3.len, &w->trap3.end);
	return (0);
}

int	open_other_img(t_window *w)
{
	int		iw;
	int		ih;

	w->char_top.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_top.xpm", &iw, &ih);
	if (w->char_top.img == NULL)
		return (-1);
	w->char_top.add = mlx_get_data_addr(w->char_top.img,
			&w->char_top.bpp, &w->char_top.len, &w->char_top.end);
	w->exit.img = mlx_xpm_file_to_image(w->mlx,
			"./img/exit.xpm", &iw, &ih);
	if (w->exit.img == NULL)
		return (-1);
	w->exit.add = mlx_get_data_addr(w->exit.img,
			&w->exit.bpp, &w->exit.len, &w->exit.end);
	w->heart.img = mlx_xpm_file_to_image(w->mlx,
			"./img/heart.xpm", &iw, &ih);
	if (w->heart.img == NULL)
		return (-1);
	w->heart.add = mlx_get_data_addr(w->heart.img,
			&w->heart.bpp, &w->heart.len, &w->heart.end);
	return (0);
}

int	open_xpm_images(t_window *w)
{
	int	error;

	error = 0;
	if (open_ground_img(w) == -1)
		error++;
	if (open_wall_img(w) == -1)
		error++;
	if (open_wall_corner_img(w) == -1)
		error++;
	if (open_char_img(w) == -1)
		error++;
	if (open_trap_img(w) == -1)
		error++;
	if (open_enemy_img(w) == -1)
		error++;
	if (open_other_img(w) == -1)
		error++;
	if (error != 0)
	{
		ft_putstr_fd("Error,\nCannot open all the XPM images.\n", 2);
		return (-1);
	}
	else
		return (0);
}
