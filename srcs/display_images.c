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

/* Display the string "Move : X" in white at the top left corner */
void	display_mouvement_count(t_window *wind)
{
	char	*number;
	char	*movements;

	number = ft_itoa(wind->obj.mvmt);
	movements = ft_strjoin("Moves : ", number);
	mlx_string_put(wind->mlx, wind->win, 10, 20, 2147483647, movements);
	free(number);
	free(movements);
}

/*	'p' (player start), 'c' (coin), '1' (wall),
 *	'0' (void), 'e' (exit)	*/
void	open_xpm_img(t_window *w)
{
	int		iw;
	int		ih;

	w->ground1.img = mlx_xpm_file_to_image(w->mlx, "./img/ground1.xpm", &iw, &ih);
	w->ground1.add = mlx_get_data_addr(w->ground1.img, &w->ground1.bpp, &w->ground1.len, &w->ground1.end);

	w->ground2.img = mlx_xpm_file_to_image(w->mlx, "./img/ground2.xpm", &iw, &ih);
	w->ground2.add = mlx_get_data_addr(w->ground2.img, &w->ground2.bpp, &w->ground2.len, &w->ground2.end);

	w->ground3.img = mlx_xpm_file_to_image(w->mlx, "./img/ground3.xpm", &iw, &ih);
	w->ground3.add = mlx_get_data_addr(w->ground3.img, &w->ground3.bpp, &w->ground3.len, &w->ground3.end);
	
	w->wall_top1.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_top1.xpm", &iw, &ih);
	w->wall_top1.add = mlx_get_data_addr(w->wall_top1.img, &w->wall_top1.bpp, &w->wall_top1.len, &w->wall_top1.end);
	
	w->wall_top2.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_top2.xpm", &iw, &ih);
	w->wall_top2.add = mlx_get_data_addr(w->wall_top2.img, &w->wall_top2.bpp, &w->wall_top2.len, &w->wall_top2.end);
	
	w->wall_top3.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_top3.xpm", &iw, &ih);
	w->wall_top3.add = mlx_get_data_addr(w->wall_top3.img, &w->wall_top3.bpp, &w->wall_top3.len, &w->wall_top3.end);

	w->wall_top_corner_right.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_top_corner_right.xpm", &iw, &ih);
	w->wall_top_corner_right.add = mlx_get_data_addr(w->wall_top_corner_right.img, &w->wall_top_corner_right.bpp, &w->wall_top_corner_right.len, &w->wall_top_corner_right.end);
	
	w->wall_top_corner_left.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_top_corner_left.xpm", &iw, &ih);
	w->wall_top_corner_left.add = mlx_get_data_addr(w->wall_top_corner_left.img, &w->wall_top_corner_left.bpp, &w->wall_top_corner_left.len, &w->wall_top_corner_left.end);
	
	w->wall_bottom_corner_right.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_bottom_corner_right.xpm", &iw, &ih);
	w->wall_bottom_corner_right.add = mlx_get_data_addr(w->wall_bottom_corner_right.img, &w->wall_bottom_corner_right.bpp, &w->wall_bottom_corner_right.len, &w->wall_bottom_corner_right.end);
	
	w->wall_bottom_corner_left.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_bottom_corner_left.xpm", &iw, &ih);
	w->wall_bottom_corner_left.add = mlx_get_data_addr(w->wall_bottom_corner_left.img, &w->wall_bottom_corner_left.bpp, &w->wall_bottom_corner_left.len, &w->wall_bottom_corner_left.end);

	w->wall_bottom.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_bottom.xpm", &iw, &ih);
	w->wall_bottom.add = mlx_get_data_addr(w->wall_bottom.img, &w->wall_bottom.bpp, &w->wall_bottom.len, &w->wall_bottom.end);

	w->wall_right.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_right.xpm", &iw, &ih);
	w->wall_right.add = mlx_get_data_addr(w->wall_right.img, &w->wall_right.bpp, &w->wall_right.len, &w->wall_right.end);

	w->wall_left.img = mlx_xpm_file_to_image(w->mlx, "./img/wall_left.xpm", &iw, &ih);
	w->wall_left.add = mlx_get_data_addr(w->wall_left.img, &w->wall_left.bpp, &w->wall_left.len, &w->wall_left.end);

	w->obstacle1.img = mlx_xpm_file_to_image(w->mlx, "./img/obstacle1.xpm", &iw, &ih);
	w->obstacle1.add = mlx_get_data_addr(w->obstacle1.img, &w->obstacle1.bpp, &w->obstacle1.len, &w->obstacle1.end);

	w->obstacle2.img = mlx_xpm_file_to_image(w->mlx, "./img/obstacle2.xpm", &iw, &ih);
	w->obstacle2.add = mlx_get_data_addr(w->obstacle2.img, &w->obstacle2.bpp, &w->obstacle2.len, &w->obstacle2.end);



//	w->p.img = mlx_xpm_file_to_image(w->mlx, "./img/p.xpm", &iw, &ih);
//	w->c.img = mlx_xpm_file_to_image(w->mlx, "./img/c.xpm", &iw, &ih);
//	w->w.img = mlx_xpm_file_to_image(w->mlx, "./img/1.xpm", &iw, &ih);
//	w->v.img = mlx_xpm_file_to_image(w->mlx, "./img/0.xpm", &iw, &ih);
//	w->e.img = mlx_xpm_file_to_image(w->mlx, "./img/e.xpm", &iw, &ih);
//	w->p.add = mlx_get_data_addr(w->p.img, &w->p.bpp, &w->p.len, &w->p.end);
//	w->c.add = mlx_get_data_addr(w->c.img, &w->c.bpp, &w->c.len, &w->c.end);
//	w->w.add = mlx_get_data_addr(w->w.img, &w->w.bpp, &w->w.len, &w->w.end);
//	w->v.add = mlx_get_data_addr(w->v.img, &w->v.bpp, &w->v.len, &w->v.end);
//	w->e.add = mlx_get_data_addr(w->e.img, &w->e.bpp, &w->e.len, &w->e.end);
}

/* Choose the correct image depending the map char */
void	put_img_to_window(char pos, t_window *wind, int x, int y)
{
	if (pos == '0' || pos == 'P' || pos == 'C' || pos == 'E')
	{
		if (wind->count == 0)
		{
			mlx_put_image_to_window(wind->mlx, wind->win, wind->ground1.img, x, y);
			wind->count++;
		}
		else if (wind->count == 1)
		{
			mlx_put_image_to_window(wind->mlx, wind->win, wind->ground2.img, x, y);
			wind->count++;
		}
		else if (wind->count > 1)
		{
			mlx_put_image_to_window(wind->mlx, wind->win, wind->ground3.img, x, y);
			wind->count = 0;
		}
	}
	else if (pos == '1')
	{
		if (y / IMG_H == 0 && y % IMG_H == 0) 
		{
			if (x / IMG_W == 0 && x % IMG_W == 0)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_top_corner_right.img, x, y);
			}
			else if (x / IMG_W == wind->obj.width - 1 && x % IMG_W == 0)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_top_corner_left.img, x, y);
			}
			else if (wind->count == 0 || wind->count == 2)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_top1.img, x, y);
				wind->count++;
			}
			else if (wind->count == 1)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_top2.img, x, y);
				wind->count++;
			}
			else if (wind->count > 2)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_top3.img, x, y);
				wind->count = 0;
			}
		}
		else if (y / IMG_H == (wind->obj.height - 1) && y % IMG_H == 0)
		{
			if (x / IMG_W != 0 && x / IMG_W != wind->obj.width - 1)
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_bottom.img, x, y);
			else if (x / IMG_W == 0)
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_bottom_corner_right.img, x, y);
			else if (x / IMG_W == wind->obj.width - 1)
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_bottom_corner_left.img, x, y);
		}
		else if (x / IMG_W == 0 && x % IMG_W == 0)
		{
			if (y / IMG_H != wind->obj.height - 1)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_right.img, x, y);
			}
		}
		else if (x / IMG_W == wind->obj.width - 1 && x % IMG_W == 0)
		{
			if (y / IMG_H != wind->obj.height - 1)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->wall_left.img, x, y);
			}
		}
		else
		{
			if (wind->count == 0)
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->obstacle1.img, x, y);
				wind->count++;
			}
			else
			{
				mlx_put_image_to_window(wind->mlx, wind->win, wind->obstacle2.img, x, y);
			}
		}
	}
	/*if (pos == 'C')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->c.img, x, y);
	else if (pos == 'E')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->e.img, x, y);
	else if (pos == 'P')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->p.img, x, y);*/
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
		if ((i + 1) == wind->obj.height)
			display_mouvement_count(wind);
		a++;
	}
	wind->count = 0;
}
