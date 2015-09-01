
#ifndef OBJECT_H
# define OBJECT_H

# include "vec3.h"
# include "material.h"

typedef enum	e_shape
{
	POLY = 1,
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
	t_vec3		rotation;
}				t_cylinder;

typedef struct	s_cone
{
	float		angle;
	t_vec3		position;
	t_vec3		rotation;
}				t_cone;

typedef struct	s_object
{
	char		*name;
	t_shape		type;
	void		*shape;
}				t_object;

t_sphere		*create_sphere(const t_vec3 *position, float radius, t_material *material);
t_cylinder		*create_cylinder(const t_vec3 *position, float radius, const t_vec3 *rotation, t_material *material);
t_cone			*create_cone(const t_vec3 *position, float angle, const t_vec3 *rotation, t_material *material);
t_vertex		*create_vertex(const t_vec3 *position, t_material *material);
t_poly			*create_poly(const t_vec3 *normal, ...);
void			poly_add(const t_vertex *vertex);
void			poly_remove(const t_vertex *vertex);

t_object		*create_object(const char *name, t_shape shape_type, void *shape);

#endif
