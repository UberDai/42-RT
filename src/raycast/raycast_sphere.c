/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 21:56:54 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/01 18:34:15 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include "object.h"
#include "raycast.h"
#include "util.h"

int		raycast_to_sphere(t_hit *hit, const t_ray *ray, const t_sphere *sphere)
{
	t_vec3	distance_to_center;
	float	tca;
	float	d2;
	float	thc;

	vec3_copy(&distance_to_center, &sphere->position);
	vec3_sub(&distance_to_center, &ray->origin);
	tca = vec3_dot(&distance_to_center, &ray->direction);

	if (tca < 0)
		return (0);

	d2 = vec3_dot(&distance_to_center, &distance_to_center) - tca * tca;

	if (d2 > sphere->radius * sphere->radius)
		return (0);

	thc = sqrt(sphere->radius * sphere->radius - d2);
	hit->distance = select_closest_hit(tca - thc, tca + thc);

	update_hit_from_ray(hit, ray, &sphere->material->ambient);

	return (1);
}
