/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_without_bn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:35:22 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/12 00:29:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
