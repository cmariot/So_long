/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 22:18:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	ft_show_key(int key, void *window)
{
	window = 0;
	ft_putnbr(key);
	ft_putchar('\n');
	return (key);
}*/

int	ft_red_cross(int key, void *window)
{
	(void)window;
	exit(EXIT_SUCCESS);
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

/*int	ft_show_mouse_position(t_window *window)
{

	int pos;
	int x;
	int y;

	x = 0;
	y = 0;
	pos = mlx_mouse_get_pos(&window, &x, &y);
	printf("pos = %d\nx = %d\ny = %d\n", pos, x, y);
	return (0);
}*/


/*void	my_mlx_pixel_put(t_window *window, int x, int y, int color)
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

 Just 1/8 of a circle 
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
}*/

int	ft_open_window(char **map, t_obj *objects)
{
	t_window	window;

	t_img		player;
	t_img		collectible;
	t_img		wall;
	t_img		space;
	t_img		start;
	t_img		exit;
	
	int		img_width;
	int		img_height;

	window.mlx_ptr = mlx_init();
	
	window.win_ptr = mlx_new_window(window.mlx_ptr, objects->width * 40, objects->height * 40, "./so_long");

	player.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/player.xpm", &img_width, &img_height);
	collectible.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/collectible.xpm", &img_width, &img_height);
	wall.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/wall.xpm", &img_width, &img_height);
	space.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/space.xpm", &img_width, &img_height);
	start.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/start.xpm", &img_width, &img_height);
	exit.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "./images/exit.xpm", &img_width, &img_height);

	player.img_addr = mlx_get_data_addr(player.img_ptr, &player.bits_per_pixel, &player.line_length, &player.endian);
	collectible.img_addr = mlx_get_data_addr(collectible.img_ptr, &collectible.bits_per_pixel, &collectible.line_length, &collectible.endian);
	wall.img_addr = mlx_get_data_addr(wall.img_ptr, &wall.bits_per_pixel, &wall.line_length, &wall.endian);
	space.img_addr = mlx_get_data_addr(space.img_ptr, &space.bits_per_pixel, &space.line_length, &space.endian);
	start.img_addr = mlx_get_data_addr(start.img_ptr, &start.bits_per_pixel, &start.line_length, &start.endian);
	exit.img_addr = mlx_get_data_addr(exit.img_ptr, &exit.bits_per_pixel, &exit.line_length, &exit.endian);

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
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, space.img_ptr, x, y);
			if (map[a][b] == '1')
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, wall.img_ptr, x, y);
			if (map[a][b] == 'C')
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, collectible.img_ptr, x, y);
			if (map[a][b] == 'P')
			{
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, start.img_ptr, x, y);
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, player.img_ptr, x, y);
			}
			if (map[a][b] == 'E')
				mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, exit.img_ptr, x, y);
			x += 40;
			b++;
		}
		y += 40;
		a++;
	}
	
	mlx_key_hook(window.win_ptr, ft_key_pressed, &window);
	mlx_hook(window.win_ptr, 17, 1L << 2, ft_red_cross, &window);
	
	mlx_loop(window.mlx_ptr);
	return (0);
}
