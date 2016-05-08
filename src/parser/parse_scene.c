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
#include "parser.h"
#include "util.h"

void		*parse_scene(const parsing_sect_t *section, t_scene *scene)
{
	t_camera	*camera;

	if (scene->name != NULL)
		free(scene->name);

	scene->name = ft_strdup(section->name);

	if (section->option_count > 0)
	{
		if (section->options[0][0] == NULL)
			die("Bad input file.");

		camera = get_camera(scene, section->options[0][1]);

		if (camera == NULL)
			die("This camera is not defined.");

		scene->active_camera = camera;
	}

	return (NULL);
}
