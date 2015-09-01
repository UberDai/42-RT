/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_gradient.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 12:46:51 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/07 22:09:41 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "gfx.h"

static void	draw_line_gradient1(t_gfx *gfx, t_vec3 *a, t_vec3 *b,
	t_color **colors)
{
	int		x;
	t_color	*color;
	t_color	*interval;
	int		tmp;

	interval = color_get_interval(colors[0], colors[1], b->x - a->x);
	color = colors[0];
	x = a->x;
	while (x < b->x)
	{
		if (colors[0]->hex < colors[1]->hex)
			color_sub(color, interval);
		else
			color_add(color, interval);
		tmp = a->y;
		tmp += ((b->y - a->y) * (x - a->x)) / (b->x - a->x);
		draw_pixel(gfx, x, tmp, color->hex);
		++x;
	}
}

static void	draw_line_gradient2(t_gfx *gfx, t_vec3 *a, t_vec3 *b,
	t_color **colors)
{
	int		y;
	t_color	*color;
	t_color	*interval;
	int		tmp;

	colors_swap(colors);
	interval = color_get_interval(colors[0], colors[1],
		ft_abs(b->y - a->y));
	color = colors[0];
	y = a->y;
	while (y < b->y)
	{
		if (colors[0]->hex > colors[1]->hex)
			color_sub(color, interval);
		else
			color_add(color, interval);
		tmp = a->x;
		tmp += ((b->x - a->x) * (y - a->y)) / (b->y - a->y);
		draw_pixel(gfx, tmp, y, color->hex);
		++y;
	}
}

void		draw_line_gradient(t_gfx *gfx, t_vec3 *pt1, t_vec3 *pt2,
	t_color **colors)
{
	if (ft_abs(pt2->x - pt1->x) > ft_abs(pt2->y - pt1->y))
	{
		if (pt1->x >= pt2->x)
			vec3_swap(&pt1, &pt2);
		draw_line_gradient1(gfx, pt1, pt2, colors);
	}
	else
	{
		if (pt1->y >= pt2->y)
			vec3_swap(&pt1, &pt2);
		draw_line_gradient2(gfx, pt1, pt2, colors);
	}
}
