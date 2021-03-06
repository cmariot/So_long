/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle_animation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:26 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 18:05:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_counter(t_window *wind)
{
	wind->count++;
	if (wind->count == 2)
		wind->count = 0;
}

void	update_obstacle(char pos, t_window *wind, int x, int y)
{
	if (pos == '0' || pos == 'C')
		update_counter(wind);
	else if (pos == '1')
	{
		if (y / IMG_H == 0 || y / IMG_H == wind->obj.height - 1)
			return ;
		else if (x / IMG_W == 0 || x / IMG_W == wind->obj. width - 1)
			return ;
		if (wind->count == 0)
			display_obstacle1(wind, x, y);
		else if (wind->count == 1)
			display_obstacle2(wind, x, y);
		else if (wind->count > 1)
			display_obstacle3(wind, x, y);
	}
}

int	obstacle_animation(t_window *wind)
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
			update_obstacle(wind->map[a][b], wind, b * IMG_W, a * IMG_H);
			b++;
		}
		a++;
	}
	wind->count = 0;
	wind->trap_count++;
	if (wind->trap_count > 3)
		wind->trap_count = 0;
	return (0);
}
