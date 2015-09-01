/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 22:17:35 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/07 22:09:07 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <libft.h>

static void	draw_line1(t_gfx *gfx, t_vec3 *a, t_vec3 *b, int color)
{
	int	x;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = a->x;
	x2 = b->x;
	y1 = a->y;
	y2 = b->y;
	x = x1;
	while (x < x2)
	{
		draw_pixel(gfx, x, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1), color);
		++x;
	}
}

static void	draw_line2(t_gfx *gfx, t_vec3 *a, t_vec3 *b, int color)
{
	int	y;
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = a->x;
	x2 = b->x;
	y1 = a->y;
	y2 = b->y;
	y = y1;
	while (y < y2)
	{
		draw_pixel(gfx, x1 + ((x2 - x1) * (y - y1)) / (y2 - y1), y, color);
		++y;
	}
}

void		draw_line(t_gfx *gfx, t_vec3 *pt1, t_vec3 *pt2, int color)
{
	if (ft_abs(pt2->x - pt1->x) > ft_abs(pt2->y - pt1->y))
	{
		if (pt1->x >= pt2->x)
			vec3_swap(&pt1, &pt2);
		draw_line1(gfx, pt1, pt2, color);
	}
	else
	{
		if (pt1->y >= pt2->y)
			vec3_swap(&pt1, &pt2);
		draw_line2(gfx, pt1, pt2, color);
	}
}
