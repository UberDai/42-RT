/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/20 20:59:47 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 06:12:17 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"
# include "material.h"

typedef enum	e_shape
{
	POLY = 1,
	PLANE,
	SPHERE,
	CYLINDER,
	CONE
}				t_shape;

typedef struct	s_vertex
{
	unsigned	id;
	t_vec3		position;
	t_material	*material;
}				t_vertex;

typedef struct	s_poly
{
	unsigned	size;
	t_vertex	*vertices;
	t_vec3		normal;
}				t_poly;

typedef struct	s_plane
{
	t_vec3		position;
	t_vec3		normal;
	t_material	*material;
}				t_plane;

typedef struct	s_sphere
{
	t_vec3		position;
	float		radius;
	t_material	*material;
}				t_sphere;

typedef struct	s_cylinder
{
	float		radius;
	t_vec3		position;
	t_vec3		axis;
	t_material	*material;
}				t_cylinder;

typedef struct	s_cone
{
	float		radius;
	t_vec3		position;
	t_vec3		axis;
	float		height;
	t_material	*material;
}				t_cone;

typedef struct	s_object
{
	char		*name;
	t_shape		type;
	void		*shape;
}				t_object;

t_plane			*create_plane(const t_vec3 *position, const t_vec3 *normal, t_material *material);
t_sphere		*create_sphere(const t_vec3 *position, float radius, t_material *material);
t_cylinder		*create_cylinder(const t_vec3 *position, const t_vec3 *axis, float radius, t_material *material);
t_cone			*create_cone(const t_vec3 *position, const t_vec3 *axis, float radius, float height, t_material *material);
t_vertex		*create_vertex(const t_vec3 *position, t_material *material);
t_poly			*create_poly(const t_vec3 *normal, ...);
void			poly_add(const t_vertex *vertex);
void			poly_remove(const t_vertex *vertex);

t_object		*create_object(const char *name, t_shape shape_type, void *shape);

#endif
