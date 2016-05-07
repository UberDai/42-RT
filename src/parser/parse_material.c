/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "parser.h"
#include <stdio.h>

static void	set_color(const parsing_sect_t *section, unsigned i, t_vec3 *vec)
{
	if (section->option_count > i)
		parse_vec3(section->options[i] + 1, vec);
	else
		vec3_set(vec, 0, 0, 0);
}

void		*parse_material(const parsing_sect_t *section, t_scene *scene)
{
	t_material	*material;
	t_vec3		ambient;
	t_vec3		diffuse;
	t_vec3		specular;

	set_color(section, 0, &ambient);
	set_color(section, 1, &diffuse);
	set_color(section, 2, &specular);

	material = create_material(section->name, &ambient, &diffuse, &specular);

	printf("%s\n", material_to_string(material));

	lst_push_back(scene->materials, material);

	return (material);
}
