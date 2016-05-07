/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:56:27 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:31:12 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <ftlst.h>
# include "camera.h"

typedef struct	s_scene
{
	char		*name;
	t_lst		*objects;
	t_lst		*lights;
	t_vec3		ambient_light;
	t_lst		*cameras;
	t_lst		*materials;
	t_camera	*active_camera;
}				t_scene;

t_scene			*create_scene(const char *name);
void			scene_destroy(t_scene *scene);

#endif
