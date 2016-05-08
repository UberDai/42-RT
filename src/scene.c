/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:57:49 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 19:10:22 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <ftlst.h>
#include "scene.h"
#include "object.h"
#include "material.h"
#include "light.h"
#include "camera.h"
#include "rt.h"

extern t_rt	rt;

t_scene		*create_scene(const char *name)
{
	t_scene	*new_scene;

	new_scene = calloc(1, sizeof(t_scene));
	new_scene->name = ft_strdup(name);
	new_scene->objects = new_lst();
	new_scene->lights = new_lst();
	new_scene->cameras = new_lst();
	new_scene->materials = new_lst();
	vec3_set(&new_scene->ambient_light, 0.2f, 0.2f, 0.2f);
	return (new_scene);
}

void		scene_destroy(t_scene *scene)
{
	lst_destroy(&(scene->objects), free);
	lst_destroy(&(scene->cameras), free);
	lst_destroy(&(scene->lights), free);
	lst_destroy(&(scene->materials), free);
	free(scene);
}

void		print_scene(const t_scene *scene)
{
	char		*str;
	t_lstiter	it;

	printf("-- OBJECTS -----------------------------------\n");
	init_iter(&it, scene->objects, increasing);
	while (lst_iterator_next(&it))
	{
		str = object_to_string((t_object*)it.data);
		printf("%s\n", str);
		free(str);
	}

	printf("\n-- MATERIALS -------------------------------\n");
	init_iter(&it, scene->materials, increasing);
	while (lst_iterator_next(&it))
	{
		str = material_to_string((t_material*)it.data);
		printf("%s\n", str);
		free(str);
	}

	printf("\n-- LIGHTS ----------------------------------\n");
	init_iter(&it, scene->lights, increasing);
	while (lst_iterator_next(&it))
	{
		str = light_to_string((t_light*)it.data);
		printf("%s\n", str);
		free(str);
	}

	printf("\n-- CAMERAS ----------------------------------\n");
	init_iter(&it, scene->cameras, increasing);
	while (lst_iterator_next(&it))
	{
		str = camera_to_string((t_camera*)it.data);
		printf("%s\n", str);
		free(str);
	}
}
