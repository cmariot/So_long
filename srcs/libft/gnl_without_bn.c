/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_without_bn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:35:22 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/14 15:58:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		total_len;
	char	*new;
	int		i;
	int		j;

	total_len = ft_strlen(str1) + ft_strlen(str2) + 1;
	new = malloc(sizeof(char) * total_len);
	if (!new)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		new[i++] = str2[j++];
	}
	new[i] = '\0';
	return (new);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			return (1);
	return (0);
}

char	*ft_gnl_get_begin(char *str)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i++] != '\n')
		len++;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_gnl_get_end(char *str)
{
	char	*new;
	int		len;
	int		bn_pos;
	int		i;

	i = 0;
	len = 1;
	bn_pos = 0;
	while (str[i++] != '\n')
		bn_pos++;
	while (str[i++] != '\0')
		len++;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	bn_pos += 1;
	i = 0;
	while (str[bn_pos] != '\0')
		new[i++] = str[bn_pos++];
	new[i] = '\0';
	return (new);
}

char	*gnl_output_without_bn(char **str, int read_return)
{
	int		len;
	char	*tmp;
	char	*ret;

	if (read_return == 0 && *str == NULL)
	{
		free(*str);
		return (NULL);
	}
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		ret = ft_gnl_get_begin(*str);
		tmp = ft_gnl_get_end(*str);
		free(*str);
		*str = tmp;
		return (ret);
	}
	ret = ft_strdup(*str);
	free(*str);
	return (ret);
}

char	*gnl_without_bn(int fd)
{
	int			read_return;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*tmp;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	while (1)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (NULL);
		buf[read_return] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str, buf);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n') || !read_return)
			break ;
	}
	return (gnl_output_without_bn(&str, read_return));
}
