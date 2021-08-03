/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 21:22:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lenght_checker(char *map_line, unsigned int map_lenght, int i)
{
	unsigned int	map_lenght_control;

	map_lenght_control = 1;
	if (i == 0)
	{
		map_lenght = ft_strlen(map_line);
	}
	else
	{
		map_lenght_control = ft_strlen(map_line);
		if (map_lenght != map_lenght_control)
		{
			ft_putstr("Error\nThe map is not rectangular.\n");
			return (-1);
		}
	}
	return (map_lenght);
}

int	ft_count_line(int file_descriptor)
{
	int		number_of_lines;
	int		read_return;
	char	tmp[2];

	number_of_lines = 0;
	while (1)
	{
		read_return = read(file_descriptor, tmp, 1);
		tmp[1] = '\0';
		if (read_return == 0)
			break ;
		if (*tmp == '\n')
			number_of_lines++;
	}
	return (number_of_lines);
}

//Memory leaks ici ! Mais si ft_strdel probleme sur certaines maps, a fix.
char	*ft_remove_backslash_n(char *str, char *tmp)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	printf("%s", str);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (len-- - 1)
	{
		tmp[i] = str[i];
		i++;
	}	
	tmp[i] = '\0';
	return (tmp);
}

char	**ft_parse_map(char *map_path)
{
	int		file_descriptor;
	char	**map;
	char	*tmp;
	int		map_width;
	int		map_lenght;
	int		i;

	//Check if the map could be open and count the lines.
	file_descriptor = open(map_path, O_RDONLY);
	if (file_descriptor == -1)
	{
		ft_putstr("Error\nThe map couldn't be open, check the name of the map.\n");
		return (NULL);
	}
	map_width = ft_count_line(file_descriptor);
	map_lenght = 0;
	close(file_descriptor);
	
	//Create an array
	map = malloc(sizeof(char **) * map_width + 1);
	if (!map)
		return (NULL);

	//Put the map in the array
	i = 0;
	file_descriptor = open(map_path, O_RDONLY);
	while (map_width--)
	{
		map[i] = get_next_line(file_descriptor);
		tmp = NULL;
		map[i] = ft_remove_backslash_n(map[i], tmp);
		free(tmp);
		i++;
	}
	map[i] = NULL;
	close(file_descriptor);
	return (map);
}
