/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/21 21:09:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:31 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "object.h"
#include <math.h>
#include <stdlib.h>

int			raycast_to_plane(t_hit *hit, const t_ray *ray, const t_plane *plane)
{
	float	dot;
	t_vec3	*to_origin;

	dot = vec3_dot(&ray->direction, &plane->normal);

	if (fabs(dot) < RC_EPSILON)
		return (COLOR_NONE);

	to_origin = vec3_sub_d(&plane->position, &ray->origin);
	hit->distance = vec3_dot(to_origin, &plane->normal) / dot;

	free(to_origin);

	if (hit->distance >= RC_EPSILON)
	{
		update_hit_from_ray(hit, ray, &plane->material->ambient);
		return (1);
	}

	return (0);
}
