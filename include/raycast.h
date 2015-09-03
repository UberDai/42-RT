/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/08 03:49:34 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "gfx.h"
# include "vec3.h"

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

t_ray			*ray(const t_vec3 *origin, const t_vec3 *direction);
t_hit			*hit(const t_vec3 *position, float distance, t_vec3 const *color);
t_vec3			*raycast(const t_ray *ray);

#endif
