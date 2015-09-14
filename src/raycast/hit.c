/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 21:59:43 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/15 00:07:39 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "raycast.h"

t_hit	*create_hit(const t_vec3 *position, float distance, t_vec3 const *color)
{
	t_hit	*hit;

	hit = (t_hit*)calloc(1, sizeof(t_hit));
	hit_set(hit, position, distance, color);
	return (hit);
}

void	hit_set(t_hit *hit, const t_vec3 *position, float distance, t_vec3 const *color)
{
	vec3_copy(&hit->position, position);
	vec3_copy(&hit->color, color);
	hit->distance = distance;
}

void	update_hit_from_ray(t_hit *hit, const t_ray *ray, float distance, const t_vec3 *color)
{
	t_vec3	position;

	vec3_copy(&position, &ray->direction);
	vec3_mult(&position, distance);
	vec3_add(&position, &ray->origin);
	hit_set(hit, &position, distance, color);
}

void	hit_copy(t_hit *dest, const t_hit *hit)
{
	memcpy(dest, hit, sizeof(t_hit));
}
