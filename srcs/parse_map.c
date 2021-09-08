/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/08 16:29:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Remove the final char of a string */
char	*ft_remove_backslash_n(char *str)
{
	int		len;
	char	*new;

	len = 0;
	len = ft_strlen(str);
	new = ft_substr(str, 0, len - 1);
	free(str);
	return (new);
}

/* Check if the map is rectangular */
int	is_rectangular(char *str, unsigned int map_len, int i, int max_index)
{
	unsigned int	control;

	if (i == 0 || i == max_index)
	{
		map_len = ft_strlen(str);
	}
	else
	{
		control = ft_strlen(str);
		if (map_len != control)
		{
			ft_putstr("Error\nThe map is not rectangular.\n");
			return (-1);
		}
	}
	return (map_len);
}

/* Count the number of lines of the map */
int	count_lines(int file_descriptor)
{
	int		number_of_lines;
	int		read_return;
	char	*tmp;

	number_of_lines = 0;
	tmp = malloc(sizeof(char) * 2);
	if (!tmp)
		return (-1);
	while (1)
	{
		read_return = read(file_descriptor, tmp, 1);
		tmp[1] = '\0';
		if (read_return == -1)
		{
			ft_putstr("Error\nThe so_long argument given is a directory.\n");
			free(tmp);
			return (-1);
		}
		if (read_return == 0)
			break ;
		if (*tmp == '\n')
			number_of_lines++;
	}
	free(tmp);
	return (number_of_lines);
}

/* Open the file for ft_count_line */
int	count_map_lines(char *map_path)
{
	int	file_descriptor;
	int	map_height;

	file_descriptor = open(map_path, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr("Error\nThe map couldn't be open.\n");
		return (-1);
	}
	map_height = count_lines(file_descriptor);
	close(file_descriptor);
	if (map_height == -1)
		return (-1);
	return (map_height);
}

/* Count the lines of the map,
   create an array to store the map,
   put the map in the array, without the '\n',
   return the map. */
char	**parse_map(char *map_path)
{
	int		file_descriptor;
	char	**map;
	int		map_height;
	int		i;

	map_height = count_map_lines(map_path);
	if (map_height == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (NULL);
	i = 0;
	file_descriptor = open(map_path, O_RDONLY);
	while (i < map_height)
	{
		map[i] = get_next_line(file_descriptor);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i] = ft_remove_backslash_n(map[i]);
		i++;
	}
	map[i] = NULL;
	close(file_descriptor);
	return (map);
}
