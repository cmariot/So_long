/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/14 15:49:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map is rectangular */
int	is_rectangular(char **map, int i)
{
	int	first_len;
	int	line_len;

	first_len = ft_strlen(map[0]);
	line_len = ft_strlen(map[i]);
	if (first_len != line_len)
	{
		ft_putstr("Error\nThe map is not rectangular.\n");
		return (0);
	}
	else
		return (1);
}

/* Count the number of lines of the map */
int	count_lines(int file_descriptor)
{
	int		number_of_lines;
	int		read_return;
	char	*tmp;

	number_of_lines = 1;
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

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
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
	file_descriptor = open(map_path, O_RDONLY);
	i = 0;
	while (i < map_height)
	{
		map[i] = gnl_without_bn(file_descriptor);
		if (map[i] == NULL)
			break ;
		i++;
	}
	if (*map[0] == '\0')
	{
		printf("Error,\nThe map is empty\n");
		free_map(&map);
		exit(0);
	}
	if (*map[i - 1] == '\0')
	{
		ft_putstr("Error\nThere is a backslash n at the end of the map.\n");
		free_map(&map);
		exit(0);
	}
	map [i] = NULL;
	close(file_descriptor);
	return (map);
}
