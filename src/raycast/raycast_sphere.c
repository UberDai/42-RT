/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/14 21:56:54 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 22:13:53 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include "object.h"
#include "raycast.h"

static float	select_closest_hit(float hit1, float hit2)
{
	float	tmp;

	if (hit1 > hit2)
	{
		tmp = hit1;
		hit1 = hit2;
		hit2 = tmp;
	}

	if (hit1 < 0)
	{
		hit1 = hit2;
		if (hit1 < 0)
			return (-1.0f);
	}

	return (hit1);
}

t_hit			*raycast_to_sphere(const t_ray *ray, const t_sphere *sphere)
{
	t_vec3	L;
	float	tca;
	float	d2;
	float	thc;
	float	hit;

	memcpy(&L, &sphere->position, sizeof(t_vec3));
	vec3_sub(&L, &ray->origin);
	tca = vec3_dot(&L, &ray->direction);

	if (tca < 0)
		return (NULL);

	d2 = vec3_dot(&L, &L) - tca * tca;

	if (d2 > sphere->radius * sphere->radius)
		return (NULL);

	thc = sqrt(sphere->radius * sphere->radius - d2);
	hit = select_closest_hit(tca - thc, tca + thc);

	return (create_hit_from_ray(ray, hit, &sphere->material->ambient));
}
