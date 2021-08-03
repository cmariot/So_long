/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 12:17:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/03 11:37:56 by cmariot          ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mvmt;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_window;



typedef struct s_perso_img
{
	void	*perso_img_ptr;
	char	*perso_img_addr;
	int		perso_bits_per_pixel;
	int		perso_line_length;
	int		perso_endian;
}	t_perso;


typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
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
void	ft_initialize(t_map *objects);
int		ft_check_map(char **map);
int		ft_check_extension(char *map_name);
int		ft_check_objects(t_map *objects);
int		ft_open_window(char **map, t_map *objects);
int		ft_move_forward(int key, t_window *window);
int		ft_turn_left(int key, t_window *window);
int		ft_move_back(int key, t_window *window);
int		ft_turn_right(int key, t_window *window);

#endif
