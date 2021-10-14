/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:35:29 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 14:19:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_top_wall(t_window *wind, int x, int y)
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

void	display_bottom_wall(t_window *wind, int x, int y)
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

void	display_wall(t_window *wind, int x, int y)
{
	if (y / IMG_H == 0 && y % IMG_H == 0)
		display_top_wall(wind, x, y);
	else if (y / IMG_H == (wind->obj.height - 1) && y % IMG_H == 0)
		display_bottom_wall(wind, x, y);
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
			display_obstacle1(wind, x, y);
		else if (wind->count == 2)
			display_obstacle3(wind, x, y);
		else
			display_obstacle2(wind, x, y);
	}
}
