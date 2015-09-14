/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 22:05:57 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "gfx.h"
# include "vec3.h"
# include "object.h"

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct	s_hit
{
	t_vec3		position;
	float		distance;
	t_vec3		color;
}				t_hit;

t_ray			*create_ray(const t_vec3 *origin, const t_vec3 *direction);
t_hit			*create_hit(const t_vec3 *position, float distance, t_vec3 const *color);
t_hit			*create_hit_from_ray(const t_ray *ray, float distance, t_vec3 const *color);
t_vec3			*raycast(const t_ray *ray);
t_hit			*raycast_to_sphere(const t_ray *ray, const t_sphere *sphere);

#endif
