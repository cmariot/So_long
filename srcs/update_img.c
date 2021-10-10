#include "so_long.h"

/* Display the correct image depending 
 * the map char and it's position on the map */
void	put_update_to_window(char pos, t_window *wind, int x, int y)
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
	else if (pos == '1')
	{
		if (y / IMG_H == 0 || y / IMG_H == wind->obj.height - 1)
			return ;
		else if (x / IMG_W == 0 || x / IMG_W == wind->obj. width - 1)
			return ;
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
	display_rules(wind);
	display_mouvement_count(wind);
	display_heart_count(wind);
	wind->count = 0;
}

