/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle_animation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:26 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 17:58:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	obstacle_animation(t_window *wind)
{
	update_img(wind);
	wind->trap_count++;
	if (wind->trap_count > 3)
		wind->trap_count = 0;
	return (0);
}
