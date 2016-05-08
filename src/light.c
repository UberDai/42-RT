/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 07:36:40 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 07:59:05 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include <stdlib.h>
#include <stdio.h>

t_light		*create_light(const t_vec3 *position, float intensity, const t_vec3 *color)
{
	t_light	*light;

	light = calloc(1, sizeof(t_light));
	vec3_copy(&light->position, position);
	vec3_copy(&light->color, color);
	light->intensity = intensity;
	return (light);
}

char			*light_to_string(const t_light *light)
{
	char	*str;
	char	*position;
	char	*color;

	position = vec3_to_string(&light->position);
	color = vec3_to_string(&light->color);

	asprintf(&str, "light(\n"
		"   position: %s,\n"
		"   color: %s,\n"
		"   intensity: %f\n"
		")",
		position,
		color,
		light->intensity);

	free(position);
	free(color);

	return (str);
}
