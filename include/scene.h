/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:56:27 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/01 21:28:17 by amaurer          ###   ########.fr       */
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
	t_lst		*cameras;
	t_camera	*active_camera;
}				t_scene;

t_scene			*create_scene(const char *name);
void			scene_destroy(t_scene *scene);

#endif
