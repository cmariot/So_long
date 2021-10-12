/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:21:56 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 12:23:10 by cmariot          ###   ########.fr       */
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
