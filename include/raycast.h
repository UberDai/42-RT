/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/21 21:50:56 by amaurer          ###   ########.fr       */
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
void			hit_set(t_hit *hit, const t_vec3 *position, float distance, t_vec3 const *color);
void			hit_copy(t_hit *dest, const t_hit *hit);
void			update_hit_from_ray(t_hit *hit, const t_ray *ray, float distance, t_vec3 const *color);
int				raycast(const t_ray *ray);
int				raycast_to_plane(t_hit *hit, const t_ray *ray, const t_plane *plane);
int				raycast_to_sphere(t_hit *hit, const t_ray *ray, const t_sphere *sphere);
int				raycast_to_poly(t_hit *hit, const t_ray *ray, const t_poly *poly);

#endif
