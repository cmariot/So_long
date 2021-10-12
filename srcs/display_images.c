/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:47:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 12:37:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_ground(t_window *wind, int x, int y)
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

void	display_heart(t_window*wind, int x, int y)
{
	mlx_put_image_to_window(wind->mlx, wind->win, wind->heart.img, x, y);
	if (wind->count < 2)
		wind->count++;
	else
		wind->count = 0;
}

void	display_character(t_window *wind, int x, int y, char pos)
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

/* Display the correct image depending 
 * the map char and it's position on the map */
void	put_img_to_window(char pos, t_window *wind, int x, int y)
{
	if (pos == '0')
		display_ground(wind, x, y);
	else if (pos == 'C')
		display_heart(wind, x, y);
	else if (pos == '1')
		display_wall(wind, x, y);
	else if (pos == 'E')
		mlx_put_image_to_window(wind->mlx,
			wind->win, wind->exit.img, x, y);
	else if (pos == 'P' || pos == 'Q' || pos == 'R' || pos == 'S')
		display_character(wind, x, y, pos);
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
