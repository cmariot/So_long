/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:47:39 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/06 13:12:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	p = player start position
	c = coin
	1 = wall
	0 = empty
	e = exit	*/
void	ft_xpm_to_img(t_window *w)
{
	int		iw;
	int		ih;

	w->p.img = mlx_xpm_file_to_image(w->mlx, "./img/p.xpm", &iw, &ih);
	w->c.img = mlx_xpm_file_to_image(w->mlx, "./img/c.xpm", &iw, &ih);
	w->m.img = mlx_xpm_file_to_image(w->mlx, "./img/1.xpm", &iw, &ih);
	w->v.img = mlx_xpm_file_to_image(w->mlx, "./img/0.xpm", &iw, &ih);
	w->e.img = mlx_xpm_file_to_image(w->mlx, "./img/e.xpm", &iw, &ih);
	w->p.add = mlx_get_data_addr(w->p.img, &w->p.bpp, &w->p.len, &w->p.end);
	w->c.add = mlx_get_data_addr(w->c.img, &w->c.bpp, &w->c.len, &w->c.end);
	w->m.add = mlx_get_data_addr(w->m.img, &w->m.bpp, &w->m.len, &w->m.end);
	w->v.add = mlx_get_data_addr(w->v.img, &w->v.bpp, &w->v.len, &w->v.end);
	w->e.add = mlx_get_data_addr(w->e.img, &w->e.bpp, &w->e.len, &w->e.end);
}

void	ft_put_img_to_window(char pos, t_window *wind, int x, int y)
{
	if (pos == '0')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->v.img, x, y);
	else if (pos == '1')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->m.img, x, y);
	if (pos == 'C')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->c.img, x, y);
	else if (pos == 'E')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->e.img, x, y);
	else if (pos == 'P')
		mlx_put_image_to_window(wind->mlx, wind->win, wind->p.img, x, y);
}

void	ft_display_movement_count(t_window *wind)
{
	char *number;
	char *movements;

	number = ft_itoa(wind->obj.mvmt);
	movements = ft_strjoin("Moves : ", number);
	mlx_string_put(wind->mlx, wind->win, 10, 20, 2147483647, movements);
	free(number);
	free(movements);
}

void	ft_print_img(t_window *wind)
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
			ft_put_img_to_window(wind->map[a][b], wind, b * IMG_W, a * IMG_H);
			ft_display_movement_count(wind);
			b++;
		}
		a++;
	}
}
