/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:57:49 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/01 21:29:21 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdlib.h>
#include <libft.h>
#include "rt.h"

extern t_rt	rt;

t_scene		*create_scene(const char *name)
{
	t_scene	*new_scene;

	new_scene = calloc(1, sizeof(t_scene));
	new_scene->name = ft_strdup(name);
	new_scene->objects = new_lst();
	new_scene->cameras = new_lst();
	new_scene->active_camera = camera(rt.width, rt.height, rt.aspect, 60.0f);
	lst_push_back(new_scene->cameras, new_scene->active_camera);
	return (new_scene);
}

void		scene_destroy(t_scene *scene)
{
	lst_destroy(&(scene->objects), free);
	lst_destroy(&(scene->cameras), free);
	free(scene);
}
