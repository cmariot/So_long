/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:47:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 17:48:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Update the ground, the obstacles and the player position,
 * not the walls, the exit or the hearts.*/
void	put_update_to_window(char pos, t_window *wind, int x, int y)
{
	if (pos == '0')
		display_ground(wind, x, y);
	else if (pos == '1')
	{
		if (y / IMG_H == 0 || y / IMG_H == wind->obj.height - 1)
			return ;
		else if (x / IMG_W == 0 || x / IMG_W == wind->obj. width - 1)
			return ;
		if (wind->count == 0)
			display_obstacle1(wind, x, y);
		else if (wind->count == 1)
			display_obstacle2(wind, x, y);
		else if (wind->count > 1)
			display_obstacle3(wind, x, y);
	}
	else if (pos == 'C')
		display_heart(wind, x, y);
	else if (pos == 'P' || pos == 'Q' || pos == 'R' || pos == 'S')
		display_character(wind, x, y, pos);
}

void	update_img(t_window *wind)
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
			put_update_to_window(wind->map[a][b], wind, b * IMG_W, a * IMG_H);
			b++;
		}
		a++;
	}
	background_color(wind, IMG_H * (wind->obj.height + 1),
		IMG_W * wind->obj.width);
	display_mouvement_count(wind);
	display_heart_count(wind);
	wind->count = 0;
}
