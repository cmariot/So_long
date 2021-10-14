/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:34:29 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 12:14:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_enemy	*new_enemy_list(int x, int y, int direction)
{
	t_enemy	*tmp;

	tmp = malloc(sizeof(t_enemy));
	if (tmp)
	{
		tmp->x = x;
		tmp->y = y;
		tmp->direction = direction;
		tmp->next = NULL;
		return (tmp);
	}
	else
		return (NULL);
}

t_enemy	*last_enemy(t_enemy *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	else
		return (NULL);
}

void	add_enemy_to_list(t_enemy **alst, t_enemy *new)
{
	t_enemy	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = last_enemy(*(alst));
			tmp->next = new;
		}
	}
}

void	get_enemy_data(t_window *window)
{
	int	first;
	int	x;
	int	y;
	int	direction;

	if (window->obj.enemy_count > 0)
	{
		x = 1;
		first = TRUE;
		while (x < window->obj.height - 1)
		{
			y = 1;
			while (y < window->obj.width - 1)
			{
				if (window->map[x][y] == '2' || window->map[x][y] == '4'
					|| window->map[x][y] == '6' || window->map[x][y] == '8')
				{
					if (first == TRUE)
					{
						direction = window->map[x][y] - '0';
						window->enemies = new_enemy_list(x, y, direction);
						first = FALSE;
					}
					else
					{
						direction = window->map[x][y] - '0';
						add_enemy_to_list(&(window->enemies),
							new_enemy_list(x, y, direction));
					}
				}
				y++;
			}
			x++;
		}
	}
}
