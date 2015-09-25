/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:23:18 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 08:50:36 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "raycast.h"
#include "gfx.h"
#include "object.h"
#include "util.h"
#include <ftlst.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

extern t_rt	rt;

static int	raycast_to_object(t_hit *hit, const t_ray *ray, const t_object *object)
{
	int		raycast_result;

	hit->object = object;

	if (object->type == SPHERE)
		raycast_result = raycast_to_sphere(hit, ray, object->shape);
	else if (object->type == PLANE)
		raycast_result = raycast_to_plane(hit, ray, object->shape);
	else if (object->type == CYLINDER)
		raycast_result = raycast_to_cylinder(hit, ray, object->shape);
	else if (object->type == CONE)
		raycast_result = raycast_to_cone(hit, ray, object->shape);
	else
		raycast_result = 0;

	return (raycast_result);
}

int		raycast_light(t_hit *hit)
{
	t_lstiter	it;
	t_ray		ray;
	t_light		*light
	int			raycast_result;

	vec3_copy(&ray.origin, hit->position);
	init_iter(&it, rt.scene->lights, increasing);
	while (lst_iterator_next(&it))
	{
		light = (t_light*)it.data;
		vec3_copy(&ray.direction, &light->position);
		vec3_sub(&ray.direction, &ray.origin);
		vec3_normalize(&ray->direction);

		raycast_result = raycast(&ray);

		if (raycast_result)
		{
			vec3_mult(&hit->color, &light->color);
		}
	}
}

int		raycast(const t_ray *ray)
{
	t_lstiter	it;
	int			raycast_result;
	t_hit		closest_hit;
	t_hit		hit;

	closest_hit.distance = -1.0f;
	init_iter(&it, rt.scene->objects, increasing);
	while (lst_iterator_next(&it))
	{
		raycast_result = raycast_to_object(&hit, ray, (t_object*)it.data);

		if (raycast_result)
		{
			if (closest_hit.distance == -1.0f || closest_hit.distance > hit.distance)
				hit_copy(&closest_hit, &hit);
		}
	}

	if (closest_hit.distance == -1.0f)
		return (COLOR_NONE);
	else
		return (raycast_light(&closest_hit));
		// return (vec3_to_color(&closest_hit.color));
}
