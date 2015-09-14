/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:23:18 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 22:05:45 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "raycast.h"
#include "gfx.h"
#include "object.h"
#include <ftlst.h>
#include <string.h>
#include <stdlib.h>
#include <libft.h>

extern t_rt	rt;

t_vec3	*raycast(const t_ray *ray)
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

	if (closest_hit == NULL)
		return (NULL);
	else
		return (vec3_clone(&closest_hit->color));
}
