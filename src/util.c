/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:12:04 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 19:09:31 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int		die(const char *message)
{
	ft_putendl(message);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	color_clamp(t_vec3 *color)
{
	if (color->x > 1.f)
		color->x = 1.0f;
	else if (color->x < 0)
		color->x = 0;
	if (color->y > 1.f)
		color->y = 1.0f;
	else if (color->y < 0)
		color->y = 0;
	if (color->z > 1.f)
		color->z = 1.0f;
	else if (color->z < 0)
		color->z = 0;
}

int		vec3_to_color(t_vec3 const *color)
{
	int		int_color;
	float	x;
	float	y;
	float	z;

	x = color->x;
	if (x > 1.f)
		x = 1.0f;
	else if (x < 0)
		x = 0;
	y = color->y;
	if (y > 1.f)
		y = 1.0f;
	else if (y < 0)
		y = 0;
	z = color->z;
	if (z > 1.f)
		z = 1.0f;
	else if (z < 0)
		z = 0;
	int_color = x * 255;
	int_color = (int_color << 8) + y * 255;
	int_color = (int_color << 8) + z * 255;
	return (int_color);
}

t_vec3	*color_to_vec3(t_vec3 *vec, int color)
{
	if (vec == NULL)
		vec = (t_vec3*)calloc(1, sizeof(t_vec3));
	vec->x = color >> 16;
	vec->y = (color >> 8) & 0xff;
	vec->z = color & 0xff;
	return (vec);
}

float	select_closest_hit(float hit1, float hit2)
{
	float	tmp;

	if (hit1 > hit2)
	{
		tmp = hit1;
		hit1 = hit2;
		hit2 = tmp;
	}
	if (hit1 < 0)
	{
		hit1 = hit2;
		if (hit1 < 0)
			return (-1.0f);
	}
	return (hit1);
}

int		solve_quadratic(float a, float b, float c, float results[2])
{
	float	disc;
	float	tmp;

	disc = b * b - 4 * a * c;
	tmp = a * 2;

	if (disc < 0)
		return (QUADRATIC_NONE);
	else if (disc == 0)
	{
		results[0] = -b / tmp;
		return (QUADRATIC_ONE);
	}
	else
	{
		disc = sqrt(disc);
		results[0] = (-b + disc) / tmp;
		results[1] = (-b - disc) / tmp;
		return (QUADRATIC_TWO);
	}
}
