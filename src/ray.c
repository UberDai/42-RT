/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:28:56 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/08 03:39:29 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include <stdlib.h>
#include <string.h>

t_ray		*ray(const t_vec3 *origin, const t_vec3 * direction)
{
	t_ray	*ray;

	ray = calloc(1, sizeof(t_ray));
	memcpy(&(ray->origin), origin, sizeof(t_vec3));
	memcpy(&(ray->direction), direction, sizeof(t_vec3));

	return (ray);
}
