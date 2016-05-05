/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"

typedef struct
{
	char		*type;
	char		*name;
	char		***options;
	unsigned	option_count;
}				parsing_sect_t;

typedef struct
{
	char		*name;
	void		*(*parser)(const parsing_sect_t *, t_scene *);
}				parsing_route_t;

t_scene		*parse_scene_file(const char *filepath);
void		*parse_scene(const parsing_sect_t *section, t_scene *scene);
void		*parse_sphere(const parsing_sect_t *section, t_scene *scene);
void		*parse_vec3(char **tokens);

#endif
