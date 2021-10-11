/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:53:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/14 15:43:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map is rectangular */
int	isnot_rectangular(char **map, int i)
{
	int	first_len;
	int	line_len;

	first_len = ft_strlen(map[0]);
	line_len = ft_strlen(map[i]);
	if (first_len != line_len)
	{
		ft_putstr_fd("Error\nThe map is not rectangular.\n", 2);
		return (1);
	}
	else
		return (0);
}

/* Authorized char :
	'0' (void), '1' (wall), 'P' (start), 'C' coin, 'E' (exit) */
int	have_unauthorized_characters(char *line, t_obj *objects, int x)
{
	int	i;

	i = 0;
	objects->width = 0;
	while (line[i])
	{
		if (line[i] == '0')
			objects->space += 1;
		else if (line[i] == '1')
			objects->wall += 1;
		else if (line[i] == 'P')
			set_player_position(objects, x, i);
		else if (line[i] == 'C')
			objects->collectible += 1;
		else if (line[i] == 'E')
			objects->exit += 1;
		else
		{
			ft_putstr_fd("Error\nThe map have unauthorized characters.\n", 2);
			return (1);
		}
		i++;
		objects->width += 1;
	}
	return (0);
}

/* Check if the first and the last lines are only composed of '1' */
int	check_firt_and_last_line(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1')
		{
			ft_putstr_fd("Error\nThe map is not surround by walls.\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

/* Check if the other lines begin and finish with '1' */
int	check_other_lines(char *map_line)
{
	int	len;

	if (map_line[0] != '1')
	{
		ft_putstr_fd("Error\nThe map is not surround by walls.\n", 2);
		return (-1);
	}
	len = ft_strlen(map_line);
	if (map_line[len - 1] != '1')
	{
		ft_putstr_fd("Error\nThe map is not surround by walls.\n", 2);
		return (-1);
	}
	return (0);
}

/* Check if the map is surounded by walls */
int	isnot_closed_by_walls(char *map, int i)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	if (i == 0 || i == j)
	{
		if (check_firt_and_last_line(map) == -1)
			return (1);
	}
	else
	{
		if (check_other_lines(map) == -1)
			return (1);
	}
	return (0);
}

/* Search if there are errors on the map */
int	isnot_correct_map(t_window *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (have_unauthorized_characters(game->map[i], &game->obj, i))
			return (1);
		if (isnot_closed_by_walls(game->map[i], i))
			return (1);
		if (isnot_rectangular(game->map, i))
			return (1);
		i++;
	}
	if (check_objects(&game->obj) == -1)
		return (1);
	return (0);
}

int	check_map(t_window *game)
{
	game_structure_init(game);
	if (isnot_correct_map(game))
	{
		free_map(game->map);
		return (-1);
	}
	else
	{
		return (0);
	}
}

