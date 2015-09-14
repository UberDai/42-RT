/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 21:59:43 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 22:06:16 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "raycast.h"

t_hit	*create_hit(const t_vec3 *position, float distance, t_vec3 const *color)
{
	t_hit	*hit;

	hit = (t_hit*)calloc(1, sizeof(t_hit));
	vec3_copy(&hit->position, position);
	vec3_copy(&hit->color, color);
	hit->distance = distance;
	return (hit);
}

t_hit	*create_hit_from_ray(const t_ray *ray, float distance, t_vec3 const *color)
{
	t_vec3	position;

	memcpy(&position, &ray->direction, sizeof(t_vec3));
	vec3_mult(&position, distance);
	vec3_add(&position, &ray->origin);

	return (create_hit(&position, distance, color));
}
