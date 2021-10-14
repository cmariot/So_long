/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_enemy_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:12 by cmariot           #+#    #+#             */
/*   Updated: 2021/10/14 12:14:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_list(t_enemy *list)
{
	while (list)
	{
		printf("x = %d, y = %d, dir = %d\n", list->x, list->y, list->direction);
		list = list->next;
	}
}

void	free_enemy_list(t_enemy **lst)
{
	t_enemy	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
