
#include "material.h"
#include <stdlib.h>

t_material		*create_material(const t_vec3 *ambient, const t_vec3 *diffuse, const t_vec3 *specular)
{
	t_material	*material;

	material = (t_material*)calloc(1, sizeof(t_material));
	vec3_copy(&material->ambient, ambient);
	vec3_copy(&material->diffuse, diffuse);
	vec3_copy(&material->specular, specular);
	return (material);
}
