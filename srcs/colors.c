/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:55:54 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/09 16:55:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//Convert sRGB color into TRGB and display it on the background	
void	background_color(t_window *win, int height, int width)
{
	int	i;
	int	j;
	int	trgb_color;

	trgb_color = create_trgb(0, 47, 47, 46);
	j = 0;
	while (j <= width)
	{
		i = win->obj.height * IMG_H - 10;
		while (i <= height)
		{
			mlx_pixel_put(win->mlx, win->win, j, i, trgb_color);
			i++;
		}
		j++;
	}
}
