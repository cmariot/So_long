/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:41:58 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/02 13:51:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_forward(int key, t_window *window)
{
	window->mvmt++;
	ft_putnbr(window->mvmt);
	ft_putstr(" Move forward");
	ft_putchar('\n');
	return (key);
}

int	ft_turn_left(int key, t_window *window)
{
	window->mvmt++;
	ft_putnbr(window->mvmt);
	ft_putstr(" Turn left");
	ft_putchar('\n');
	return (key);
}

int	ft_move_back(int key, t_window *window)
{
	window->mvmt++;
	ft_putnbr(window->mvmt);
	ft_putstr(" Go back");
	ft_putchar('\n');
	return (key);
}

int	ft_turn_right(int key, t_window *window)
{
	window->mvmt++;
	ft_putnbr(window->mvmt);
	ft_putstr(" Turn right");
	ft_putchar('\n');
	return (key);
}