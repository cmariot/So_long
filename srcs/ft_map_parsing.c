/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:19:52 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 01:03:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lenght_checker(char *map_line, unsigned int map_lenght, int i)
{
	unsigned int	map_lenght_control;

	if (i == 0)
		map_lenght = ft_strlen(map_line) - 1;
	else
	{
		map_lenght_control = ft_strlen(map_line) - 1;
		if (map_lenght != map_lenght_control)
		{
			ft_putstr("Error\nThe map is not rectangular.\n");
			return (-1);
		}
	}
	if (map_lenght == 0)
	{
		ft_putstr("Error\nThe map is empty.\n");
		return (-1);
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
	close(file_descriptor);
	return (number_of_lines);
}

//Memory leaks ici ! Mais si ft_strdel probleme sur certaines maps, a fix.
char	*ft_remove_backslash_n(char *str, int str_len)
{
	char	*tmp;

	tmp = ft_strdup(str);
//	ft_strdel(&str);
	str = ft_substr(tmp, 0, str_len);
//	ft_strdel(&tmp);
	return (str);
}

char	**ft_save_map(int file_descriptor, char *map_path)
{
	char	**map;
	int		map_width;
	int		map_lenght;
	int		i;

	map_width = ft_count_line(file_descriptor);
	file_descriptor = open(map_path, O_RDONLY);
	map = malloc(sizeof(char **) * map_width + 1);
	if (!map)
		return (NULL);
	i = 0;
	while (1)
	{
		map[i] = get_next_line(file_descriptor);
		if (!map[i])
			break ;
		map_lenght = map_lenght_checker(map[i], map_lenght, i);
		if (map_lenght == -1)
			return (NULL);
			map[i] = ft_remove_backslash_n(map[i], map_lenght);
		i++;
	}
	map[i] = NULL;
	close(file_descriptor);
	return (map);
}
