/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 19:57:22 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/02 20:15:32 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "rt.h"
#include "object.h"
#include "raycast.h"
#include "vec3.h"
#include <stdlib.h>

t_rt	rt;

void	init(void)
{
	rt.gfx = calloc(1, sizeof(t_gfx));
	rt.width = 300;
	rt.height = 300;
	rt.gfx->width = rt.width;
	rt.gfx->height= rt.height;
}

int		main(void)
{
	init();

	rt.scene = create_scene("Test");

	t_sphere	*new_sphere;
	t_object	*new_object;

	new_sphere = create_sphere(vec3_new(0, 0, 10.0f), 1.0f, NULL);
	new_object = create_object("lol", SPHERE, new_sphere);
	lst_push_back(rt.scene->objects, new_object);

	mlx_initialize(rt.gfx);

	return (0);
}
