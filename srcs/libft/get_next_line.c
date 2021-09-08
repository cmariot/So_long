/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 09:44:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_return;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (NULL);
		buf[read_return] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else if (str != NULL)
			ft_add_buf_to_str(&str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (gnl_outpout(read_return, &str));
}

void	ft_add_buf_to_str(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = tmp;
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	s1_size;
	size_t	s2_size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	size_t	src_len;
	char	*src;
	char	*cpy;
	size_t	i;

	src = (char *)s1;
	src_len = ft_strlen(src);
	cpy = malloc(sizeof(char) * (src_len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*gnl_outpout(ssize_t read_return, char **str_input)
{
	int		len;
	char	*tmp;
	char	*str_return;

	if (read_return == 0 && **str_input == '\0')
	{
		ft_strdel(str_input);
		return (NULL);
	}
	len = 0;
	while ((*str_input)[len] != '\n' && (*str_input)[len] != '\0')
		len++;
	if ((*str_input)[len] == '\n')
	{
		str_return = ft_substr(*str_input, 0, len + 1);
		tmp = ft_strdup(&(*str_input)[len + 1]);
		ft_strdel(str_input);
		*str_input = tmp;
		return (str_return);
	}
	str_return = ft_substr(*str_input, 0, len);
	ft_strdel(str_input);
	return (str_return);
}
