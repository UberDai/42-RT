/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:23:18 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/15 00:21:34 by amaurer          ###   ########.fr       */
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

	if (object->type == SPHERE)
		raycast_result = raycast_to_sphere(hit, ray, object->shape);
	else
		raycast_result = 0;

	return (raycast_result);
}

int		raycast(const t_ray *ray)
{
	t_lstiter	iter;
	int			raycast_result;
	t_hit		closest_hit;
	t_hit		hit;

	closest_hit.distance = -1.0f;
	init_iter(&iter, rt.scene->objects, increasing);
	while (lst_iterator_next(&iter))
	{
		raycast_result = raycast_to_object(&hit, ray, (t_object*)iter.data);

		if (raycast_result != 0)
		{
			if (closest_hit.distance == -1.0f || closest_hit.distance > hit.distance)
				hit_copy(&closest_hit, &hit);
		}
	}

	if (closest_hit.distance == -1.0f)
		return (COLOR_NONE);
	else
		return (vec3_to_color(&closest_hit.color));
}
