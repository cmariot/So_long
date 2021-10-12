/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:53:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 11:52:51 by cmariot          ###   ########.fr       */
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

/* Check if the map is surounded by walls :
 * for the first and the last lines, the lines must be only composed by '1'
 * for the other lines they must start and end by '1'*/
int	isnot_closed_by_walls(char *map_line, int current_index, char **map_array)
{
	int	i;
	int	error;
	int	max_index;

	max_index = 0;
	while (map_array[max_index] != NULL)
		max_index++;
	error = 0;
	if (current_index == 0 || current_index == max_index - 1)
	{
		i = 0;
		while (map_line[i] != '\0')
			if (map_line[i++] != '1')
				error++;
	}
	else
	{
		max_index = ft_strlen(map_line) - 1;
		if (map_line[0] != '1' || map_line[max_index] != '1')
			error++;
	}
	if (error == 0)
		return (0);
	ft_putstr_fd("Error,\nThe map is not closed by walls\n", 2);
	return (error);
}

/* The map must be only composed by authorized characters.
 * Authorized char :
 * '0' (void), '1' (wall), 'P' (start), 'C' coin, 'E' (exit) */
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
			ft_putstr_fd("Error\nThe map has unauthorized characters.\n", 2);
			return (1);
		}
		i++;
		objects->width += 1;
	}
	return (0);
}

/* Search if there are errors on the map,
 * make test on each lines.*/
int	isnot_correct_map(t_window *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		if (have_unauthorized_characters(game->map[i], &game->obj, i))
			return (1);
		if (isnot_closed_by_walls(game->map[i], i, game->map))
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
	if (game->map == NULL)
		exit(EXIT_FAILURE);
	init_structure(game);
	if (isnot_correct_map(game))
	{
		free_map(game->map);
		exit(EXIT_FAILURE);
	}
	else
	{
		return (0);
	}
}
