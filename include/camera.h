/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 20:04:50 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/09 01:30:36 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"

typedef struct s_scene	t_scene;

typedef struct	s_viewplane
{
	float		width;
	float		height;
	float		distance;
	t_vec3		upleft;
}				t_viewplane;

typedef struct	s_camera
{
	char		*name;
	t_vec3		position;
	t_vec3		direction;
	unsigned	resolution_width;
	unsigned	resolution_height;
	t_viewplane	viewplane;
}				t_camera;

t_camera		*create_camera(unsigned width, unsigned height, float aspect, float fov);
void			camera_update_viewplane(t_camera *camera);
char			*camera_to_string(const t_camera *camera);
t_camera		*get_camera(const t_scene *scene, const char *name);

#endif
