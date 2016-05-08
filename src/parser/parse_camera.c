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
#include "camera.h"
#include "parser.h"
#include "util.h"

void		*parse_camera(const parsing_sect_t *section, t_scene *scene)
{
	t_camera	*camera;
	t_vec3		position;
	t_vec3		direction;
	t_vec3		resolution;
	
	vec3_set(&position, 0.f, 0.f, 0.f);
	
	if (section->option_count > 0)
		parse_vec3(section->options[0] + 1, &position);

	vec3_set(&direction, 1.f, 1.f, 1.f);
	
	if (section->option_count > 1)
		parse_vec3(section->options[1] + 1, &direction);

	vec3_set(&resolution, 1.f, 1.f, 1.f);
	
	if (section->option_count > 2)
		parse_vec3(section->options[2] + 1, &resolution);

	camera = create_camera(resolution.x, resolution.y, resolution.x / resolution.y, 60.f);
	
	if (camera->name != NULL)
		free(camera->name);

	camera->name = ft_strdup(section->name);
	vec3_copy(&camera->position, &position);
	vec3_copy(&camera->direction, &direction);

	lst_push_back(scene->cameras, camera);

	return (camera);
}
