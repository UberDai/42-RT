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
#include "parser.h"
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
	rt.scene = parse_scene_file("scenes/00");
	print_scene(rt.scene);
	mlx_initialize(rt.gfx);

	return (0);
}
