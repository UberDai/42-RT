/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/13 22:16:01 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 00:09:02 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <libft.h>
#include <ftlst.h>
#include "material.h"

t_material		*create_material(const char *name, const t_vec3 *ambient, const t_vec3 *diffuse, const t_vec3 *specular)
{
	t_material	*material;

	material = (t_material*)calloc(1, sizeof(t_material));
	material->name = ft_strdup(name);
	vec3_copy(&material->ambient, ambient);
	vec3_copy(&material->diffuse, diffuse);
	vec3_copy(&material->specular, specular);
	return (material);
}

char			*material_to_string(const t_material *material)
{
	char	*str;
	char	*ambient;
	char	*diffuse;
	char	*specular;

	ambient = vec3_to_string(&material->ambient);
	diffuse = vec3_to_string(&material->diffuse);
	specular = vec3_to_string(&material->specular);

	asprintf(&str, "material %s(\n"
		"   ambient: %s,\n"
		"   diffuse: %s,\n"
		"   specular: %s\n"
		")",
		material->name,
		ambient,
		diffuse,
		specular);

	free(ambient);
	free(diffuse);
	free(specular);

	return (str);
}

t_material		*get_material(const t_scene *scene, const char *name)
{
	t_lstiter	it;
	t_material	*material;

	init_iter(&it, scene->materials, increasing);
	while (lst_iterator_next(&it))
	{
		material = (t_material*)it.data;

		if (ft_strequ(material->name, name))
			return (material);
	}

	return (NULL);
}
