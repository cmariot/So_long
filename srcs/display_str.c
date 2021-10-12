/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:29:49 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 13:07:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Convert sRGB color into TRGB	
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

//Display a grey rectangular background behind the rules, heart counter 
void	background_color(t_window *win, int height, int width)
{
	int	i;
	int	j;
	int	trgb_color;

	trgb_color = create_trgb(0, 47, 47, 46);
	j = 0;
	while (j <= width)
	{
		i = win->obj.height * IMG_H - 10;
		while (i <= height)
		{
			mlx_pixel_put(win->mlx, win->win, j, i, trgb_color);
			i++;
		}
		j++;
	}
}

/* Display the string "Moves : X" on the screen */
void	display_mouvement_count(t_window *wind)
{
	char	*number;
	char	*movements;

	if (wind->obj.mvmt > INT_MAX)
		return ;
	number = ft_itoa(wind->obj.mvmt);
	movements = ft_strjoin("Moves : ", number);
	mlx_string_put(wind->mlx, wind->win, 40,
		IMG_H * (wind->obj.height + 1) - 15, INT_MAX, movements);
	free(number);
	free(movements);
}

/* Display the string "Collected : X / X" on the screen */
void	display_heart_count(t_window *wind)
{
	char	*collected;
	char	*collectible;
	char	*tmp;

	if (wind->obj.collectible > INT_MAX)
		return ;
	if (wind->obj.collected > INT_MAX)
		return ;
	collected = ft_itoa(wind->obj.collected);
	tmp = ft_strjoin("Collected : ", collected);
	free(collected);
	collected = ft_strdup(tmp);
	free(tmp);
	collectible = ft_itoa(wind->obj.collectible);
	tmp = ft_strjoin(" / ", collectible);
	free(collectible);
	collectible = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(collected, collectible);
	free(collectible);
	free(collected);
	mlx_string_put(wind->mlx, wind->win, 40,
		IMG_H * (wind->obj.height + 1) - 35, INT_MAX, tmp);
	free(tmp);
}

/* Display the rules on the screen, 
 * if the window is too small just display keys */
void	display_rules(t_window *wind)
{
	char	*rules;
	char	*additional;
	char	*all;

	if (wind->obj.width > 12)
	{
		rules = ft_strdup("Collect all the hearts before leaving the place. ");
		additional = ft_strdup("Move with WASD keys.");
		all = ft_strjoin(rules, additional);
		mlx_string_put(wind->mlx, wind->win,
			40, IMG_H * wind->obj.height - 15, INT_MAX, all);
		free(rules);
		free(all);
	}
	else
	{
		additional = ft_strdup("Move with WASD keys.");
		mlx_string_put(wind->mlx, wind->win, 40,
			IMG_H * wind->obj.height - 15, 2147483647, additional);
	}
	free(additional);
}
