/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:43:00 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/11 17:56:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
		free(map);
	map = NULL;
}

void	free_img_pt2(t_window *window)
{
	if (window->wall_bottom.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_bottom.img);
	if (window->wall_right.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_right.img);
	if (window->wall_left.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_left.img);
	if (window->trap1.img != NULL)
		mlx_destroy_image(window->mlx, window->trap1.img);
	if (window->trap2.img != NULL)
		mlx_destroy_image(window->mlx, window->trap2.img);
	if (window->trap3.img != NULL)
		mlx_destroy_image(window->mlx, window->trap3.img);
	if (window->heart.img != NULL)
		mlx_destroy_image(window->mlx, window->heart.img);
	if (window->exit.img != NULL)
		mlx_destroy_image(window->mlx, window->exit.img);
	if (window->char_top.img != NULL)
		mlx_destroy_image(window->mlx, window->char_top.img);
	if (window->char_left.img != NULL)
		mlx_destroy_image(window->mlx, window->char_left.img);
	if (window->char_right.img != NULL)
		mlx_destroy_image(window->mlx, window->char_right.img);
	if (window->char_down.img != NULL)
		mlx_destroy_image(window->mlx, window->char_down.img);
}

void	free_img(t_window *window)
{
	if (window->wall_bottom_corner_right.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_bottom_corner_right.img);
	if (window->wall_bottom_corner_left.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_bottom_corner_left.img);
	if (window->ground1.img != NULL)
		mlx_destroy_image(window->mlx, window->ground1.img);
	if (window->ground2.img != NULL)
		mlx_destroy_image(window->mlx, window->ground2.img);
	if (window->ground3.img != NULL)
		mlx_destroy_image(window->mlx, window->ground3.img);
	if (window->wall_top1.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_top1.img);
	if (window->wall_top2.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_top2.img);
	if (window->wall_top3.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_top3.img);
	if (window->wall_top_corner_right.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_top_corner_right.img);
	if (window->wall_top_corner_left.img != NULL)
		mlx_destroy_image(window->mlx, window->wall_top_corner_left.img);
}

/* Exit if we close the window by clicking on the cross */
int	red_cross(t_window *window)
{
	free_map(window->map);
	free_img(window);
	free_img_pt2(window);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/* If ESC is pressed */
int	close_window(int key, t_window *window)
{
	free_map(window->map);
	free_img(window);
	free_img_pt2(window);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(EXIT_SUCCESS);
	return (key);
}

/* MLX hook : if a key is pressed do action and print a new img */
int	key_pressed(int key, t_window *wind)
{
	if (key == ESC_KEY)
		close_window(key, wind);
	else if (key == W_KEY)
		move_forward(key, wind);
	else if (key == A_KEY)
		turn_left(key, wind);
	else if (key == S_KEY)
		move_back(key, wind);
	else if (key == D_KEY)
		turn_right(key, wind);
	wind->trap_count++;
	if (wind->trap_count > 3)
		wind->trap_count = 0;
	update_img(wind);
	return (0);
}

/* Set the mlx_ptr and create a window, mlx loop until exit() */
int	open_window(t_window *wind)
{
	int			win_h;
	int			win_w;

	wind->mlx = mlx_init();
	win_h = (wind->obj.height + 1) * IMG_H;
	win_w = wind->obj.width * IMG_W;
	wind->win = mlx_new_window(wind->mlx, win_w, win_h, "./so_long");
	if (open_xpm_img(wind) == -1)
		close_window(0, wind);
	background_color(wind, win_h, win_w);
	print_img(wind);
	mlx_key_hook(wind->win, key_pressed, wind);
	mlx_hook(wind->win, 33, 1L << 5, red_cross, wind);
	mlx_loop(wind->mlx);
	return (0);
}
