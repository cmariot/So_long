/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/02 22:19:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_show_key(int key, void *window)
{
	window = 0;
	ft_putnbr(key);
	ft_putchar('\n');
	return (key);
}

int	ft_close_window(int key, t_window *window)
{
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
	return (key);
}

int	ft_key_pressed(int key, void *window)
{
	if (key == 53)
		ft_close_window(key, window);
	else if (key == 13)
		ft_move_forward(key,window);
	else if (key == 0)
		ft_turn_left(key,window);
	else if (key == 1)
		ft_move_back(key,window);
	else if (key == 2)
		ft_turn_right(key,window);
	return (0);
}

int	ft_expose_pressed(int key, void *window)
{
	if (key)
		ft_close_window(1, window);
	else
	{
		ft_putnbr(key);
		ft_putchar('\n');
	}
	return (0);
}

void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
{
	char	*dst;

	dst = window->img_addr + (y * window->line_length + x * (window->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_print_square(t_window window, int size, int pos_x, int pos_y, int color)
{
	int x;
	int y;

	y = 0;
	while (y != size)
	{
		x = 0;
		while (x != size)
		{
			my_mlx_pixel_put(&window, pos_x + x, pos_y + y, color);
			mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img_ptr, 0, 0);
			x++;
		}
		y++;
	}
}

/* Just 1/8 of a circle */
void	ft_print_circle(t_window window, int radius, int a, int b, int color)
{
	int x;
	int y;
	int d;

	x = 0;
	y = radius;
	d = radius - 1;
	while (y >= x)
	{
		my_mlx_pixel_put(&window, a + x, b + y, color);
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img_ptr, 0, 0);
		if (d >= x * 2)
		{
			d = d - 2 * x - 1;
			x++;
		}
		else if (d < 2 * (radius - y))
		{
			d = d + 2 * y - 1;
			y = y - 1;
		}
		else
		{
			d = d + 2 * (y - x - 1);
			y = y - 1;
			x = x + 1;
		}
	}
}

int	ft_open_window(char **map, t_map *objects)
{
	t_window	window;
	char *relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./images/beton.xpm";
	window.mvmt = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, objects->width * 40, objects->height * 40, "./so_long");
	window.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, relative_path, &img_width, &img_height);
//	window.img_ptr = mlx_new_image(window.mlx_ptr, objects->width * 100, objects->height * 100);
	window.img_addr = mlx_get_data_addr(window.img_ptr, &window.bits_per_pixel, &window.line_length, &window.endian);

	printf("WIDTH = %d\n", objects->width);
	int x;
	int y;
	int j;
	int i;
	int a;
	int b;
	
	i = objects->height;
	a = 0;
	b = 0;
	x = 0;
	y = 0;
	while (i--)
	{
		j = objects->width;
		x = 0;
		b = 0;
		while (j--)
		{
			if (map[a][b] == '0' || map[a][b] == 'P' || map[a][b] == 'C' || map[a][b] == 'E')
			{
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img_ptr, 0 + x, 0 + y);
			}
			x += 40;
			b++;
		}
		y += 40;
		a++;
	}

//	ft_print_square(window, 100, 100, 100, 0x00FF0000);
//	ft_print_circle(window, 100, 100, 100, 0x00FF0000);
	mlx_hook(window.win_ptr, 02, 1L << 0, ft_key_pressed, &window);
	free(map);
	free(objects);
	mlx_loop(window.mlx_ptr);
	return (0);
}
