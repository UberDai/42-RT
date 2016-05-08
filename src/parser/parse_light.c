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

#include <stdlib.h>
#include <libft.h>
#include "light.h"
#include "parser.h"
#include "util.h"

void		*parse_light(const parsing_sect_t *section, t_scene *scene)
{
	t_light		*light;
	t_vec3		position;
	t_vec3		color;
	float		intensity;
	
	vec3_set(&position, 0.f, 0.f, 0.f);
	
	if (section->option_count > 0)
		parse_vec3(section->options[0] + 1, &position);

	vec3_set(&color, 1.f, 1.f, 1.f);
	
	if (section->option_count > 1)
		parse_vec3(section->options[1] + 1, &color);

	intensity = 0.f;

	if (section->option_count > 2)
		intensity = atof(section->options[2][1]);

	light = create_light(&position, intensity, &color);
	lst_push_back(scene->lights, light);

	return (light);
}
