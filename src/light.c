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

t_light		*create_light(const t_vec3 *position, float intensity, const t_vec3 *color)
{
	t_light	*light;

	light = calloc(1, sizeof(t_light));
	vec3_copy(&light->position, position);
	vec3_copy(&light->color, color);
	light->intensity = intensity;
	return (light);
}
