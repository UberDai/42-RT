/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "gfx.h"
# include "vec3.h"
# include "object.h"

# define RC_EPSILON			0.0001f
# define RC_SHADOW_SHIFT	0.01f

typedef struct	s_ray
{
	t_vec3		origin;
	t_vec3		direction;
	float		length;
	unsigned	depth;
}				t_ray;

typedef struct	s_hit
{
	t_vec3		position;
	float		distance;
	t_vec3		color;
	t_vec3		normal;
	t_object	*object;
}				t_hit;

t_ray			*create_ray(const t_vec3 *origin, const t_vec3 *direction);
t_hit			*create_hit(const t_vec3 *position, float distance, t_vec3 const *color);
void			hit_reset(t_hit *hit);
void			hit_set(t_hit *hit, const t_vec3 *position, float distance, t_vec3 const *color);
void			hit_copy(t_hit *dest, const t_hit *hit);
void			update_hit_from_ray(t_hit *hit, const t_ray *ray, t_vec3 const *color);
int				raycast(const t_ray *ray, t_hit *hit, unsigned depth, t_object *exclude);
int				raycast_to_plane(t_hit *hit, const t_ray *ray, const t_plane *plane);
int				raycast_to_sphere(t_hit *hit, const t_ray *ray, const t_sphere *sphere);
int				raycast_to_poly(t_hit *hit, const t_ray *ray, const t_poly *poly);
int				raycast_to_cylinder(t_hit *hit, const t_ray *ray, const t_cylinder *cylinder);
int				raycast_to_cone(t_hit *hit, const t_ray *ray, const t_cone *cone);

#endif
