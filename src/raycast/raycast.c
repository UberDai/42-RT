/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:23:18 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/01 19:12:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "raycast.h"
#include "gfx.h"
#include "object.h"
#include "light.h"
#include "util.h"
#include "color.h"
#include <ftlst.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

extern t_rt	rt;

static int	raycast_to_object(t_hit *hit, const t_ray *ray, const t_object *object)
{
	int		raycast_result;

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

	if (raycast_result)
		hit->object = (t_object *)object;

	return (raycast_result);
}

static void	raycast_light(t_hit *hit, unsigned depth)
{
	t_lstiter	it;
	t_ray		ray;
	t_light		*light;
	int			raycast_result;
	t_vec3		lightness;
	t_hit		sub_hit;

	if (depth == 0)
		return ;

	vec3_set(&lightness, 0, 0, 0);
	vec3_copy(&ray.origin, &hit->position);
	init_iter(&it, rt.scene->lights, increasing);
	while (lst_iterator_next(&it))
	{
		light = (t_light*)it.data;
		vec3_copy(&ray.direction, &light->position);
		vec3_sub(&ray.direction, &ray.origin);
		vec3_normalize(&ray.direction);
		raycast_result = raycast(&ray, &sub_hit, depth - 1, NULL);

		if (sub_hit.object != NULL)
		{
			// ray bounce
		}
		else
		{
			vec3_add(&lightness, &light->color);
		}
	}

	lightness.x /= rt.scene->lights->size;
	lightness.y /= rt.scene->lights->size;
	lightness.z /= rt.scene->lights->size;

	hit->color.x *= lightness.x;
	hit->color.y *= lightness.y;
	hit->color.z *= lightness.z;
}

int		raycast(const t_ray *ray, t_hit *hit, unsigned depth, t_object *exclude)
{
	t_lstiter	it;
	int			raycast_result;
	t_hit		closest_hit;
	t_object	*object;

	hit_reset(hit);

	if (depth == 0)
		return (0);

	hit_reset(&closest_hit);
	init_iter(&it, rt.scene->objects, increasing);
	while (lst_iterator_next(&it))
	{
		object = (t_object*)it.data;

		if (object == exclude)
			continue ;

		raycast_result = raycast_to_object(hit, ray, object);

		if (raycast_result)
		{
			if (closest_hit.object == NULL || closest_hit.distance > hit->distance)
				hit_copy(&closest_hit, hit);
		}
	}

	hit_copy(hit, &closest_hit);

	if (closest_hit.object == NULL)
	{
		return (0);
	}
	else
	{
		raycast_light(hit, depth);
		return (1);
	}
}
