/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/11 16:00:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_the_map(t_window *window)
{
	if (check_map(window) == -1)
	{
		free_map(window->map);
		return (-1);
	}
	return (0);
}

/* Check if the map is rectangular */
int	is_rectangular(char **map, int i)
{
	int	first_len;
	int	line_len;

	first_len = ft_strlen(map[0]);
	line_len = ft_strlen(map[i]);
	if (first_len != line_len)
	{
		ft_putstr_fd("Error\nThe map is not rectangular.\n", 2);
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
			ft_putstr_fd("Error\nThe argument is a directory.\n", 2);
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
		ft_putstr_fd("Error\nThe map couldn't be open.\n", 2);
		return (-1);
	}
	map_height = count_lines(file_descriptor);
	close(file_descriptor);
	if (map_height == -1)
		return (-1);
	return (map_height);
}

void	print_parsing_error(char **map, int i, int file_descriptor)
{
	if (*map[0] == '\0')
	{
		close(file_descriptor);
		ft_putstr_fd("Error,\nThe map is empty.\n", 2);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (*map[i - 1] == '\0')
	{
		ft_putstr_fd("Error\nThere is a backslash n at the end of the map.\n", 2);
		free_map(map);
		close(file_descriptor);
		exit(EXIT_FAILURE);
	}
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
	map = malloc(sizeof(char **) * (map_height + 1));
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
	map[i] = NULL;
	if (*map[0] == '\0' || *map[i - 1] == '\0')
		print_parsing_error(map, i, file_descriptor);
	close(file_descriptor);
	return (map);
}
