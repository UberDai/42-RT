/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 05:12:15 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:33 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "object.h"
#include "util.h"
#include <math.h>

int		raycast_to_cone(t_hit *hit, const t_ray *ray, const t_cone *cone)
{
	float	results[2];
	float	a;
	float	b;
	float	c;
	int		quad_result;

	a = ray->direction.z * ray->direction.z +
		ray->direction.y * ray->direction.y -
		ray->direction.x * ray->direction.x;

	b = 2 * ray->origin.z * ray->direction.z +
		2 * ray->origin.y * ray->direction.y -
		2 * ray->origin.x * ray->direction.x;

	c = ray->origin.z * ray->origin.z +
		ray->origin.y * ray->origin.y -
		ray->origin.x * ray->origin.x;

	if ((quad_result = solve_quadratic(a, b, c, results)) == QUADRATIC_NONE)
		return (0);
	else if (quad_result == QUADRATIC_ONE)
		hit->distance = results[0];
	else
		hit->distance = select_closest_hit(results[0], results[1]);

	if (hit->distance <= RC_EPSILON)
		return (0);

	update_hit_from_ray(hit, ray, &cone->material->ambient);

	return (1);
}
