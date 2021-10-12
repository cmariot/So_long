/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 14:36:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/* Print an error and exit the program if :
 * - The map is empty
 * - There is a '\n' just before the end of file */
void	print_parsing_error(char **map, int i)
{
	if (*map[0] == '\0')
	{
		ft_putstr_fd("Error,\nThe map is empty.\n", 2);
		free_map(map);
		exit(EXIT_FAILURE);
	}
	else if (*map[i - 1] == '\0')
	{
		ft_putstr_fd("Error\nThere is a backslash n at the end of the map.\n", 2);
		free_map(map);
		exit(EXIT_FAILURE);
	}
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
int	openmap_and_countlines(char *map_path)
{
	int	file_descriptor;
	int	map_height;

	file_descriptor = open(map_path, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr_fd("Error\nThe map cannot be open.\n", 2);
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
char	**store_map(char *map_path)
{
	int		file_descriptor;
	char	**map;
	int		map_height;
	int		i;

	map_height = openmap_and_countlines(map_path);
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
		if (map[i++] == NULL)
			break ;
	}
	map[i] = NULL;
	close(file_descriptor);
	if (*map[0] == '\0' || *map[i - 1] == '\0')
		print_parsing_error(map, i);
	return (map);
}
