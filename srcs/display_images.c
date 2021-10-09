/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:47:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/08 15:07:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Display the string "Moves : X" on the screen */
void	display_mouvement_count(t_window *wind)
{
	char	*number;
	char	*movements;

	if (wind->obj.mvmt > INT_MAX)
		return;
	number = ft_itoa(wind->obj.mvmt);
	movements = ft_strjoin("Moves : ", number);
	mlx_string_put(wind->mlx, wind->win, 40,
		IMG_H * (wind->obj.height + 1) - 15, INT_MAX, movements);
	free(number);
	free(movements);
}

/* Display the string "Collected : X / X" on the screen */
void	display_heart_count(t_window *wind)
{
	char	*collected;
	char	*collectible;
	char	*tmp;

	if (wind->obj.collectible > INT_MAX)
		return ;
	if (wind->obj.collected > INT_MAX)
		return ;
	collected = ft_itoa(wind->obj.collected);
	tmp = ft_strjoin("Collected : ", collected);
	free(collected);
	collected = ft_strdup(tmp);
	free(tmp);
	collectible = ft_itoa(wind->obj.collectible);
	tmp = ft_strjoin(" / ", collectible);
	free(collectible);
	collectible = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(collected, collectible);
	free(collectible);
	free(collected);
	mlx_string_put(wind->mlx, wind->win, 40,
		IMG_H * (wind->obj.height + 1) - 35, INT_MAX, tmp);
	free(tmp);
}

/* Display the rules on the screen,
   if the window is too small just display keys */
void	display_rules(t_window *wind)
{
	char	*rules;
	char	*additional;
	char	*all;

	if (wind->obj.width > 12)
	{
		rules = ft_strdup("Collect all the hearts before leaving the place. ");
		additional = ft_strdup("Move with WASD keys.");
		all = ft_strjoin(rules, additional);
		mlx_string_put(wind->mlx, wind->win,
			40, IMG_H * wind->obj.height - 15, INT_MAX, all);
		free(rules);
		free(all);
	}
	else
	{
		additional = ft_strdup("Move with WASD keys.");
		mlx_string_put(wind->mlx, wind->win, 40,
			IMG_H * wind->obj.height  - 15, 2147483647, additional);
	}
	free(additional);
}

/* Open the XPM images and save their address */
void	open_xpm_img(t_window *w)
{
	int		iw;
	int		ih;

	w->ground1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground1.xpm", &iw, &ih);
	w->ground1.add = mlx_get_data_addr(w->ground1.img,
			&w->ground1.bpp, &w->ground1.len, &w->ground1.end);
	w->ground2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground2.xpm", &iw, &ih);
	w->ground2.add = mlx_get_data_addr(w->ground2.img,
			&w->ground2.bpp, &w->ground2.len, &w->ground2.end);
	w->ground3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/ground3.xpm", &iw, &ih);
	w->ground3.add = mlx_get_data_addr(w->ground3.img,
			&w->ground3.bpp, &w->ground3.len, &w->ground3.end);
	w->wall_top1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top1.xpm", &iw, &ih);
	w->wall_top1.add = mlx_get_data_addr(w->wall_top1.img,
			&w->wall_top1.bpp, &w->wall_top1.len, &w->wall_top1.end);
	w->wall_top2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top2.xpm", &iw, &ih);
	w->wall_top2.add = mlx_get_data_addr(w->wall_top2.img,
			&w->wall_top2.bpp, &w->wall_top2.len, &w->wall_top2.end);
	w->wall_top3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top3.xpm", &iw, &ih);
	w->wall_top3.add = mlx_get_data_addr(w->wall_top3.img,
			&w->wall_top3.bpp, &w->wall_top3.len, &w->wall_top3.end);
	w->wall_top_corner_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top_corner_right.xpm", &iw, &ih);
	w->wall_top_corner_right.add = mlx_get_data_addr(
			w->wall_top_corner_right.img,
			&w->wall_top_corner_right.bpp, &w->wall_top_corner_right.len,
			&w->wall_top_corner_right.end);
	w->wall_top_corner_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_top_corner_left.xpm", &iw, &ih);
	w->wall_top_corner_left.add = mlx_get_data_addr(w->wall_top_corner_left.img,
			&w->wall_top_corner_left.bpp, &w->wall_top_corner_left.len,
			&w->wall_top_corner_left.end);
	w->wall_bottom_corner_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom_corner_right.xpm", &iw, &ih);
	w->wall_bottom_corner_right.add = mlx_get_data_addr(
			w->wall_bottom_corner_right.img,
			&w->wall_bottom_corner_right.bpp, &w->wall_bottom_corner_right.len,
			&w->wall_bottom_corner_right.end);
	w->wall_bottom_corner_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom_corner_left.xpm", &iw, &ih);
	w->wall_bottom_corner_left.add = mlx_get_data_addr(
			w->wall_bottom_corner_left.img,
			&w->wall_bottom_corner_left.bpp, &w->wall_bottom_corner_left.len,
			&w->wall_bottom_corner_left.end);
	w->wall_bottom.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_bottom.xpm", &iw, &ih);
	w->wall_bottom.add = mlx_get_data_addr(w->wall_bottom.img,
			&w->wall_bottom.bpp, &w->wall_bottom.len, &w->wall_bottom.end);
	w->wall_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_right.xpm", &iw, &ih);
	w->wall_right.add = mlx_get_data_addr(w->wall_right.img,
			&w->wall_right.bpp, &w->wall_right.len, &w->wall_right.end);
	w->wall_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/wall_left.xpm", &iw, &ih);
	w->wall_left.add = mlx_get_data_addr(w->wall_left.img,
			&w->wall_left.bpp, &w->wall_left.len, &w->wall_left.end);
	w->trap1.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap1.xpm", &iw, &ih);
	w->trap1.add = mlx_get_data_addr(w->trap1.img,
			&w->trap1.bpp, &w->trap1.len, &w->trap1.end);
	w->trap2.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap2.xpm", &iw, &ih);
	w->trap2.add = mlx_get_data_addr(w->trap2.img,
			&w->trap2.bpp, &w->trap2.len, &w->trap2.end);
	w->trap3.img = mlx_xpm_file_to_image(w->mlx,
			"./img/trap3.xpm", &iw, &ih);
	w->trap3.add = mlx_get_data_addr(w->trap3.img,
			&w->trap3.bpp, &w->trap3.len, &w->trap3.end);
	w->heart.img = mlx_xpm_file_to_image(w->mlx,
			"./img/heart.xpm", &iw, &ih);
	w->heart.add = mlx_get_data_addr(w->heart.img,
			&w->heart.bpp, &w->heart.len, &w->heart.end);
	w->exit.img = mlx_xpm_file_to_image(w->mlx,
			"./img/exit.xpm", &iw, &ih);
	w->exit.add = mlx_get_data_addr(w->exit.img,
			&w->exit.bpp, &w->exit.len, &w->exit.end);
	w->char_down.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_down.xpm", &iw, &ih);
	w->char_down.add = mlx_get_data_addr(w->char_down.img,
			&w->char_down.bpp, &w->char_down.len, &w->char_down.end);
	w->char_left.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_left.xpm", &iw, &ih);
	w->char_left.add = mlx_get_data_addr(w->char_left.img,
			&w->char_left.bpp, &w->char_left.len, &w->char_left.end);
	w->char_right.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_right.xpm", &iw, &ih);
	w->char_right.add = mlx_get_data_addr(w->char_right.img,
			&w->char_right.bpp, &w->char_right.len, &w->char_right.end);
	w->char_top.img = mlx_xpm_file_to_image(w->mlx,
			"./img/char_top.xpm", &iw, &ih);
	w->char_top.add = mlx_get_data_addr(w->char_top.img,
			&w->char_top.bpp, &w->char_top.len, &w->char_top.end);
}

/* Display the correct image depending the map char and it's position on the map */
void	put_img_to_window(char pos, t_window *wind, int x, int y)
{
	if (pos == '0')
	{
		if (wind->count == 0)
			mlx_put_image_to_window(wind->mlx,
				wind->win, wind->ground1.img, x, y);
		else if (wind->count == 1)
			mlx_put_image_to_window(wind->mlx,
				wind->win, wind->ground2.img, x, y);
		else if (wind->count > 1)
			mlx_put_image_to_window(wind->mlx,
				wind->win, wind->ground3.img, x, y);
		if (wind->count < 2)
			wind->count++;
		else
			wind->count = 0;
	}
	else if (pos == 'C')
	{
		mlx_put_image_to_window(wind->mlx, wind->win, wind->heart.img, x, y);
		if (wind->count < 2)
			wind->count++;
		else
			wind->count = 0;
	}
	else if (pos == '1')
	{
		if (y / IMG_H == 0 && y % IMG_H == 0)
		{
			if (x / IMG_W == 0 && x % IMG_W == 0)
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_top_corner_right.img, x, y);
			else if (x / IMG_W == wind->obj.width - 1 && x % IMG_W == 0)
				mlx_put_image_to_window(wind->mlx, wind->win,
					wind->wall_top_corner_left.img, x, y);
			else if (wind->count == 0 || wind->count == 2)
			{
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_top1.img, x, y);
				wind->count++;
			}
			else if (wind->count == 1)
			{
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_top2.img, x, y);
				wind->count++;
			}
			else if (wind->count > 2)
			{
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_top3.img, x, y);
				wind->count = 0;
			}
		}
		else if (y / IMG_H == (wind->obj.height - 1) && y % IMG_H == 0)
		{
			if (x / IMG_W != 0 && x / IMG_W != wind->obj.width - 1)
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_bottom.img, x, y);
			else if (x / IMG_W == 0)
				mlx_put_image_to_window(wind->mlx, wind->win,
					wind->wall_bottom_corner_right.img, x, y);
			else if (x / IMG_W == wind->obj.width - 1)
				mlx_put_image_to_window(wind->mlx, wind->win,
					wind->wall_bottom_corner_left.img, x, y);
		}
		else if (x / IMG_W == 0 && x % IMG_W == 0)
		{
			if (y / IMG_H != wind->obj.height - 1)
				mlx_put_image_to_window(wind->mlx,
					wind->win, wind->wall_right.img, x, y);
		}
		else if (x / IMG_W == wind->obj.width - 1 && x % IMG_W == 0)
		{
			if (y / IMG_H != wind->obj.height - 1)
				mlx_put_image_to_window(wind->mlx, wind->win,
					wind->wall_left.img, x, y);
		}
		else
		{
			if (wind->count == 0)
			{
				if (wind->trap_count == 0)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap1.img, x, y);
				else if (wind->trap_count == 1)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				else if (wind->trap_count == 2)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap3.img, x, y);
				else if (wind->trap_count == 3)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				wind->count++;
			}
			else if (wind->count == 1)
			{
				if (wind->trap_count == 0)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				else if (wind->trap_count == 1)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap3.img, x, y);
				else if (wind->trap_count == 2)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				else if (wind->trap_count == 3)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap1.img, x, y);
				wind->count++;
			}
			else if (wind->count > 1)
			{
				if (wind->trap_count == 0)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap3.img, x, y);
				else if (wind->trap_count == 1)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				else if (wind->trap_count == 2)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap1.img, x, y);
				else if (wind->trap_count == 3)
					mlx_put_image_to_window(wind->mlx,
						wind->win, wind->trap2.img, x, y);
				wind->count = 0;
			}
		}
	}
	else if (pos == 'E')
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->exit.img, x, y);
	else if (pos == 'P' || pos == 'Q' || pos == 'R' || pos == 'S')
	{
		if (pos == 'P')
			mlx_put_image_to_window(wind->mlx, wind->win,
				wind->char_down.img, x, y);
		else if (pos == 'Q')
			mlx_put_image_to_window(wind->mlx, wind->win,
				wind->char_left.img, x, y);
		else if (pos == 'R')
			mlx_put_image_to_window(wind->mlx, wind->win,
				wind->char_right.img, x, y);
		else if (pos == 'S')
			mlx_put_image_to_window(wind->mlx, wind->win,
				wind->char_top.img, x, y);
		if (wind->count < 2)
			wind->count++;
		else
			wind->count = 0;
	}
}

/* Check all the characters of the map,
 * On every char put the correct image at its position */
void	print_img(t_window *wind)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = wind->obj.height;
	a = 0;
	while (i--)
	{
		j = wind->obj.width;
		b = 0;
		while (j--)
		{
			put_img_to_window(wind->map[a][b], wind, b * IMG_W, a * IMG_H);
			b++;
		}
		a++;
	}
	background_color(wind, IMG_H * (wind->obj.height + 1),
		IMG_W * wind->obj.width);
	display_rules(wind);
	display_mouvement_count(wind);
	display_heart_count(wind);
	wind->count = 0;
}
