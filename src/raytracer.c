/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:23:18 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/08 23:39:25 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "raycast.h"
#include "gfx.h"
#include "object.h"
#include <ftlst.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <libft.h>

extern t_rt	rt;

static t_hit		*create_hit(const t_ray *ray, float distance, int color)
{
	t_vec3	position;

	memcpy(&position, &(ray->direction), sizeof(t_vec3));
	vec3_mult(&position, distance);
	vec3_add(&position, &(ray->origin));

	return (hit(&position, distance, color));
}

static t_hit		*raycast_to_sphere(const t_ray *ray, const t_sphere *sphere)
{
	t_vec3	L;
	float	tca;
	float	d2;
	float	thc;
	float	hits[2] = { 0 };

	memcpy(&L, &(sphere->position), sizeof(t_vec3));
	vec3_sub(&L, &(ray->origin));
	tca = vec3_dot(&L, &(ray->direction));

	if (tca < 0)
		return (NULL);

	d2 = vec3_dot(&L, &L) - tca * tca;

	if (d2 > sphere->radius * sphere->radius)
		return (NULL);

	thc = sqrt(sphere->radius * sphere->radius - d2);

	hits[0] = tca - thc;
	hits[1] = tca + thc;

	// ----------------

	if (hits[0] > hits[1])
	{
		float	tmp;
		tmp = hits[0];
		hits[0] = hits[1];
		hits[1] = tmp;
	}

	if (hits[0] < 0)
	{
		hits[0] = hits[1];
		if (hits[0] < 0)
			return (NULL);
	}

	return (create_hit(ray, hits[0], COLOR_WHITE));
}

int		raycast(const t_ray *ray)
{
	t_lstiter	iter;
	t_object	*object;
	t_hit		*hit;
	t_hit		*closest_hit;

	closest_hit = NULL;
	init_iter(&iter, rt.scene->objects, increasing);
	while (lst_iterator_next(&iter))
	{
		object = iter.data;
		if (object->type == SPHERE)
			hit = raycast_to_sphere(ray, object->shape);

		if (hit != NULL && (closest_hit == NULL || closest_hit->distance > hit->distance))
			closest_hit = hit;
	}

	return (COLOR_NONE);
}

t_hit	*hit(const t_vec3 *position, float distance, int color)
{
	t_hit	*hit;

	hit = calloc(1, sizeof(t_hit));
	memcpy(&(hit->position), position, sizeof(t_vec3));
	hit->distance = distance;
	hit->color = color;
	return (hit);
}
