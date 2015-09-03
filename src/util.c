/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:12:04 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/08 03:40:03 by amaurer          ###   ########.fr       */
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

int		vec3_color(t_vec3 const *color)
{
	int		int_color;

	int_color = color->x;
	int_color = (int_color << 8) + color->y;
	int_color = (int_color << 8) + color->z;
	return (int_color);
}
