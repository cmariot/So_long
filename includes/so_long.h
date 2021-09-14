/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/14 14:33:43 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"

#define BUFFER_SIZE 10
# define IMG_H 40
# define IMG_W 40

# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97

typedef struct s_obj
{
	int	height;
	int	width;
	int	start;
	int	collected;
	int	collectible;
	int	exit;
	int	wall;
	int	space;
	int	mvmt;
	int	player_x;
	int	player_y;
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
	char	**map;
	void	*mlx;
	void	*win;
	t_obj	obj;
	t_img	p;
	t_img	c;
	t_img	w;
	t_img	v;
	t_img	e;
}	t_window;

// SO LONG
int		check_extension(char *map_name);
char	**parse_map(char *map_path);
int		check_map(t_window *wind);
int		is_rectangular(char *str, unsigned int len, int i, int max_index);
void	struct_init(t_window *window);
int		check_objects(t_obj *objects);
void	set_player_position(t_obj *objects, int x, int i);
int		open_window(t_window *window);
void	open_xpm_img(t_window *w);
void	put_img_to_window(char pos, t_window *wind, int x, int y);
void	print_img(t_window *wind);
int		move_forward(int key, t_window *wind);
int		turn_left(int key, t_window *wind);
int		move_back(int key, t_window *wind);
int		turn_right(int key, t_window *wind);
void	free_map(char ***map);

// GET NEXT LINE
char	*gnl_without_bn(int fd);

// LIBFT
int		ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size);

#endif
