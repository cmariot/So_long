/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:34:29 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/13 12:33:58 by cmariot          ###   ########.fr       */
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
	int first;
	int	x;
	int	y;
	int	direction;

	if (window->obj.enemy_count > 0)
	{
		x = 1;
		direction = 2;
		first = TRUE;
		while (x < window->obj.height - 2)
		{
			y = 1;
			while (y < window->obj.width - 2)
			{
				if (window->map[x][y] == '6')
				{
					if (first == TRUE)
					{
						printf("x = %d, y = %d, direction = %d\n", x, y, direction);	
						window->enemies = new_enemy_list(x, y, direction);
						direction += 2;
						first = FALSE;
					}
					else
					{
						add_enemy_to_list(&window->enemies, new_enemy_list(x, y, direction));
						printf("x = %d, y = %d, direction = %d\n", x, y, direction);	
						direction += 2;
						if (direction == 10)
							direction = 2;
					}
				}
				y++;
			}
			x++;
		}
	}
}

