/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:20:58 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/01 21:20:43 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "raycast.h"
#include "gfx.h"
#include <string.h>

static void	set_ray_direction(t_ray *ray, const t_camera *camera, int increment_x, int increment_y)
{
	t_vec3	tmp;
	t_vec3	destination;

	vec3_copy(&destination, &camera->viewplane.upleft);

	vec3_set(&tmp, increment_x, 0, 0);
	vec3_add(&destination, &tmp);

	vec3_set(&tmp, 0, increment_y, 0);
	vec3_add(&destination, &tmp);

	vec3_copy(&ray->direction, &destination);
	vec3_sub(&ray->direction, &ray->origin);
	vec3_normalize(&ray->direction);
}

void	draw(t_rt *rt)
{
	int			x;
	int			y;
	float		increment_x;
	float		increment_y;
	t_camera	*camera;
	t_ray		ray;

	camera = rt->scene->active_camera;
	increment_x = camera->viewplane.width / camera->resolution_width;
	increment_y = camera->viewplane.height / camera->resolution_height;

	vec3_copy(&ray.origin, &camera->position);

	y = 0;
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			set_ray_direction(&ray, camera, increment_x * x, increment_y * y);
			raycast(&ray);
			x++;
		}
		y++;
	}

	mlx_update(rt->gfx);
}
