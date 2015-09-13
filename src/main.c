/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 19:57:22 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 00:24:59 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "rt.h"
#include "object.h"
#include "raycast.h"
#include "vec3.h"
#include "material.h"
#include "util.h"
#include <stdlib.h>

t_rt	rt;

void	init(void)
{
	rt.gfx = calloc(1, sizeof(t_gfx));
	rt.width = 1200;
	rt.height = 800;
	rt.aspect = (float)rt.width / rt.height;
	rt.gfx->width = rt.width;
	rt.gfx->height = rt.height;
}

int		main(void)
{
	init();

	rt.scene = create_scene("Test");

	t_material	*red = create_material(
		vec3_new(1.0f, 0, 0),
		vec3_new(1.0f, 0, 0),
		vec3_new(1.0f, 0, 0)
	);

	t_material	*blue = create_material(
		vec3_new(0, 0, 1.0f),
		vec3_new(0, 0, 1.0f),
		vec3_new(0, 0, 1.0f)
	);

	t_sphere	*new_sphere;
	t_object	*new_object;

	new_sphere = create_sphere(vec3_new(-0.5f, 0, 9.7f), 1.0f, red);
	new_object = create_object("lol", SPHERE, new_sphere);
	lst_push_back(rt.scene->objects, new_object);

	new_sphere = create_sphere(vec3_new(0.5f, 0, 10.0f), 1.0f, blue);
	new_object = create_object("lol", SPHERE, new_sphere);
	lst_push_back(rt.scene->objects, new_object);

	mlx_initialize(rt.gfx);

	return (0);
}
