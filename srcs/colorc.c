/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:34:44 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/02 15:48:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int	get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int	get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	main(void)
{
	int color;

	color = create_trgb(0, 257, 87, 52);
	printf("COLOR = %d\n", color);
	printf("%d\n", get_t(16865075));
	printf("%d\n", get_r(16865075));
	printf("%d\n", get_g(16865075));
	printf("%d\n", get_b(16865075));
	return (0);
}
