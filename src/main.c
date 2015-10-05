/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 19:57:22 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 19:30:56 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "rt.h"
#include "object.h"
#include "light.h"
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

void	create_basic_scene(void)
{
	t_vec3		color;
	t_vec3		position;
	t_vec3		axis;
	t_material	*material;

	rt.scene = create_scene("Test");

	vec3_set(&color, 1.0f, 0, 0);
	material = create_material(&color, &color, &color);
	vec3_set(&position, -2.0f, 0.0f, 2.0f);
	lst_push_back(rt.scene->objects,
		create_object("sphere1", SPHERE,
			create_sphere(&position, 0.5f, material)
		)
	);

	vec3_set(&color, 0, 0, 1.0f);
	material = create_material(&color, &color, &color);
	vec3_set(&position, 0.0f, 0.0f, 2.0f);
	lst_push_back(rt.scene->objects,
		create_object("sphere2", SPHERE,
			create_sphere(&position, 1.5f, material)
		)
	);

	vec3_set(&color, 0, 1.0f, 0);
	material = create_material(&color, &color, &color);
	vec3_set(&position, 0, -2.5f, 0);
	vec3_set(&axis, 0.2f, 1.0f, 0);
	lst_push_back(rt.scene->objects,
		create_object("plane", PLANE,
			create_plane(&position, &axis, material)
		)
	);

	// vec3_set(&color, 1.0f, 1.0f, 0);
	// material = create_material(&color, &color, &color);
	// vec3_set(&position, 0, 0, 10.0f);
	// vec3_set(&axis, 1.0f, 1.0f, -1.0f);
	// lst_push_back(rt.scene->objects,
	// 	create_object("cylinder", CYLINDER,
	// 		create_cylinder(&position, &axis, 0.8f, material)
	// 	)
	// );

	// vec3_set(&color, 0, 1.0f, 1.0f);
	// material = create_material(&color, &color, &color);
	// vec3_set(&position, 10.0f, 0, 0);
	// vec3_set(&axis, 1.0f, 1.0f, -1.0f);
	// lst_push_back(rt.scene->objects,
	// 	create_object("cone", CONE,
	// 		create_cone(&position, &axis, 3.0f, 10.0f, material)
	// 	)
	// );

	vec3_set(&position, 5.0f, 3.0f, -4.0f);
	vec3_set(&color, 1.0f, 1.0f, 1.0f);
	lst_push_back(rt.scene->lights,
		create_light(&position, 1.0f, &color)
	);

	vec3_set(&position, -3.0f, 3.0f, -4.0f);
	vec3_set(&color, 1.0f, 1.0f, 1.0f);
	lst_push_back(rt.scene->lights,
		create_light(&position, 1.0f, &color)
	);
}

int		main(void)
{
	init();
	create_basic_scene();
	mlx_initialize(rt.gfx);

	return (0);
}
