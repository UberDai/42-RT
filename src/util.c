/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:12:04 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 00:23:19 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"
#include <stdlib.h>

int		die(const char *message)
{
	ft_putendl(message);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int		vec3_to_color(t_vec3 const *color)
{
	int		int_color;

	int_color = color->x * 255;
	int_color = (int_color << 8) + color->y * 255;
	int_color = (int_color << 8) + color->z * 255;
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
