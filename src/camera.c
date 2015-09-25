/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/08 23:26:47 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 07:33:38 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void		camera_update_viewplane(t_camera *camera)
{
	t_vec3		*upleft;
	t_vec3		xVector;
	t_vec3		yVector;
	t_vec3		zVector;

	vec3_copy(&zVector, &camera->direction);
	vec3_mult(&zVector, camera->viewplane.distance);

	vec3_set(&xVector, 1.0f, 0, 0);
	vec3_mult(&xVector, camera->viewplane.width / 2.0f);

	vec3_set(&yVector, 0, 1.0f, 0);
	vec3_mult(&yVector, camera->viewplane.height / 2.0f);

	upleft = &camera->viewplane.upleft;
	vec3_copy(upleft, &camera->position);
	vec3_add(upleft, &zVector);
	vec3_add(upleft, &yVector);
	vec3_sub(upleft, &xVector);
}

t_camera	*camera(unsigned width, unsigned height, float aspect, float fov)
{
	t_camera	*new_camera;

	(void)fov;
	new_camera = calloc(1, sizeof(t_camera));
	new_camera->resolution_width = width;
	new_camera->resolution_height = height;
	new_camera->viewplane.width = 1.0f;
	new_camera->viewplane.height = 1.0f / aspect;
	new_camera->viewplane.distance = 1.0f;
	vec3_set(&new_camera->direction, 0, 0, 1.0f);
	vec3_set(&new_camera->position, 0, 0, -5.0f);
	camera_update_viewplane(new_camera);
	return (new_camera);
}
