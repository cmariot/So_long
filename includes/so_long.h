/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/04 18:26:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 10
# define MLX_SYNC_IMAGE_WRITABLE 1
# define MLX_SYNC_WIN_FLUSH_CMD 2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_obj
{
	int	height;
	int	width;
	int	start;
	int	collectible;
	int	exit;
	int	wall;
	int	space;
	int	mvmt;
}	t_obj;

typedef struct s_img
{
	void	*img;
	char	*add;
	int		bpp;
	int		len;
	int		end;
}	t_img;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_img	p;
	t_img	c;
	t_img	m;
	t_img	v;
	t_img	s;
	t_img	e;
}	t_window;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
char	**ft_parse_map(char *map_path);
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
void	ft_initialize(t_obj *objects);
int		ft_check_map(char **map);
int		ft_check_extension(char *map_name);
int		ft_check_objects(t_obj *objects);
int		ft_open_window(char **map, t_obj *objects);
int		ft_move_forward(int key, t_obj *obj);
int		ft_turn_left(int key, t_obj *obj);
int		ft_move_back(int key, t_obj *obj);
int		ft_turn_right(int key, t_obj *obj);
void	ft_xpm_to_img(t_window *w);
void	ft_put_img_to_window(char pos, t_window wind, int x, int y);
void	ft_print_img(t_window wind, char **map, t_obj *objects);

#endif
