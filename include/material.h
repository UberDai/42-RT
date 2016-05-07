
#ifndef MATERIAL_H
# define MATERIAL_H

# include "vec3.h"

typedef struct	s_material
{
	char		*name;
	t_vec3		ambient;
	t_vec3		diffuse;
	t_vec3		specular;
	int			illumination;
	float		shininess;
	float		opacity;
}				t_material;

t_material		*create_material(const char *name, const t_vec3 *ambient, const t_vec3 *diffuse, const t_vec3 *specular);
char			*material_to_string(const t_material *material);

#endif
