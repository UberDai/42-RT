/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:20:58 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/29 21:39:35 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "raycast.h"
#include "util.h"
#include <string.h>
#include <stdlib.h>

static void	set_ray_direction(t_ray *ray, const t_camera *camera, float increment_x, float increment_y)
{
	t_vec3	dest;

	vec3_copy(&dest, &camera->viewplane.upleft);
	dest.x += increment_x;
	dest.y -= increment_y;

	vec3_copy(&ray->direction, &dest);
	vec3_sub(&ray->direction, &ray->origin);
	vec3_normalize(&ray->direction);
}

void	render(t_rt *rt)
{
	int			x;
	int			y;
	float		increment_x;
	float		increment_y;
	t_camera	*camera;
	t_ray		ray;
	int			color;

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
			color = raycast(&ray, 2);

			if (color != COLOR_NONE)
				draw_pixel(rt->gfx, x, y, color);
			x++;
		}
		y++;
	}
	mlx_update(rt->gfx);
}
