/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 19:57:22 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/19 20:56:14 by amaurer          ###   ########.fr       */
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

void	create_basic_scene(void)
{
	t_vec3		color;
	t_vec3		position;
	t_material	*material;

	rt.scene = create_scene("Test");

	vec3_set(&color, 1.0f, 0, 0);
	material = create_material(&color, &color, &color);
	vec3_set(&position, -0.5f, 0, 9.7f);
	lst_push_back(rt.scene->objects,
		create_object("sphere1", SPHERE,
			create_sphere(&position, 1.0f, material)
		)
	);

	vec3_set(&color, 0, 0, 1.0f);
	material = create_material(&color, &color, &color);
	vec3_set(&position, 0.5f, 0, 10.0f);
	lst_push_back(rt.scene->objects,
		create_object("sphere2", SPHERE,
			create_sphere(&position, 1.0f, material)
		)
	);
}

int		main(void)
{
	init();
	create_basic_scene();
	mlx_initialize(rt.gfx);

	return (0);
}
