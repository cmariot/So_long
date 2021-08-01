/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/01 20:27:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_map
{
	int	height;
	int	width;
	int	start;
	int	collectible;
	int	exit;
	int	wall;
	int	space;
}	t_map;

int		ft_check_extension(char *map_name);
void	ft_putstr(char *str);
char	**ft_save_map(int file_descriptor, char *map_path);
char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size);
char	*ft_strdel(char **adr_str);
void	ft_add_buf_to_str(char **str, void *buf);
char	*gnl_outpout(ssize_t read_return, char **str_input);
int		ft_check_map(char **map);
void	ft_initialize(t_map *objects);
int		ft_check_objects(t_map *objects);
int		ft_open_window(char **map, t_map *objects);

#endif
