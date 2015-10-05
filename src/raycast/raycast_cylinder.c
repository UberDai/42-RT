/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 04:22:09 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:32 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "object.h"
#include "util.h"
#include <math.h>

int		raycast_to_cylinder(t_hit *hit, const t_ray *ray, const t_cylinder *cylinder)
{
	t_vec3		cyl_distance;
	float		d;
	float		t;
	float		s;
	t_vec3		n;
	t_vec3		O;
	float		length;
	float		results[2];

	cyl_distance = ray->origin;
	vec3_sub(&cyl_distance, &cylinder->position);

	vec3_copy(&n, &ray->direction);
	vec3_cross(&n, &cylinder->axis);

	length = vec3_magnitude(&n);

	if (length < RC_EPSILON && length > -RC_EPSILON)
		return (0);

	vec3_normalize(&n);

	d = fabs(vec3_dot(&cyl_distance, &n));

	if (d <= cylinder->radius)
	{
		vec3_copy(&O, &cyl_distance);
		vec3_cross(&O, &cylinder->axis);

		t = - vec3_dot(&O, &n) / length;

		vec3_copy(&O, &n);
		vec3_cross(&O, &cylinder->axis);
		vec3_normalize(&O);

		s = fabs(sqrtf(cylinder->radius * cylinder->radius - d * d) / vec3_dot(&ray->direction, &O));

		results[0] = t - s;
		results[1] = t + s;

		if (results[0] < -RC_EPSILON && results[1] < -RC_EPSILON)
			return (0);

		hit->distance = select_closest_hit(results[0], results[1]);
		update_hit_from_ray(hit, ray, &cylinder->material->ambient);

		// t_vec3 HB;
		// HB = newPosition;
		// HB.Subtract(&cylinder->position);

		// float scale = HB.Dot(&cylinder->axis);
		// normal.x = HB.x - cylinder->axis.x * scale;
		// normal.y = HB.y - cylinder->axis.y * scale;
		// normal.z = HB.z - cylinder->axis.z * scale;
		// normal.Normalize();

		return (1);
	}

	return (0);
}
