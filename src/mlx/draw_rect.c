/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 18:19:25 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/07 22:06:29 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	draw_rect(t_gfx *gfx, t_vec3 *pt, unsigned int size[], int color)
{
	unsigned int		i;

	i = 0;
	while (i < size[0])
	{
		draw_pixel(gfx, pt->x + i, pt->y, color);
		draw_pixel(gfx, pt->x + i, pt->y + size[1], color);
		i++;
	}
	i = 0;
	while (i < size[1])
	{
		draw_pixel(gfx, pt->x, pt->y + i, color);
		draw_pixel(gfx, pt->x + size[0], pt->y + i, color);
		i++;
	}
}

void	draw_filled_rect(t_gfx *gfx, t_vec3 *pt, unsigned int size[],
	int color)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			draw_pixel(gfx, pt->x + i, pt->y + j, color);
			j++;
		}
		i++;
	}
}
