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

#include "object.h"
#include "parser.h"

void		*parse_sphere(const parsing_sect_t *section, t_scene *scene)
{
	t_sphere	*sphere;
	
	(void)section;
	(void)scene;
	sphere = create_sphere(0, 0, 0);

	return (sphere);
}
