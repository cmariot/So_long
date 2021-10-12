/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:27:50 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:35:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* The last 'P' will be the start position */
void	set_player_position(t_obj *objects, int x, int i)
{
	objects->player_y = i;
	objects->player_x = x;
	objects->start += 1;
}

/* The height of the map = number of char * in the array */
int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/* Set all the img pointer at NULL */
void	init_images(t_window *wind)
{
	wind->ground1.img = NULL;
	wind->ground2.img = NULL;
	wind->ground3.img = NULL;
	wind->wall_top1.img = NULL;
	wind->wall_top2.img = NULL;
	wind->wall_top3.img = NULL;
	wind->wall_top_corner_left.img = NULL;
	wind->wall_top_corner_right.img = NULL;
	wind->wall_bottom_corner_left.img = NULL;
	wind->wall_bottom_corner_right.img = NULL;
	wind->wall_left.img = NULL;
	wind->wall_right.img = NULL;
	wind->wall_bottom.img = NULL;
	wind->trap1.img = NULL;
	wind->trap2.img = NULL;
	wind->trap3.img = NULL;
	wind->char_down.img = NULL;
	wind->char_left.img = NULL;
	wind->char_right.img = NULL;
	wind->char_top.img = NULL;
	wind->heart.img = NULL;
	wind->exit.img = NULL;
}

/* Set initial value of the objects structure */
void	init_structure(t_window *wind)
{
	wind->count = 0;
	wind->trap_count = 0;
	wind->obj.height = get_map_height(wind->map);
	wind->obj.width = 0;
	wind->obj.start = 0;
	wind->obj.collected = 0;
	wind->obj.collectible = 0;
	wind->obj.exit = 0;
	wind->obj.wall = 0;
	wind->obj.space = 0;
	wind->obj.mvmt = 0;
	init_images(wind);
}
