/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 20:52:00 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 06:26:16 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

t_sphere		*create_sphere(const t_vec3 *position, float radius, t_material *material)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)calloc(1, sizeof(t_sphere));
	vec3_copy(&sphere->position, position);
	sphere->radius = radius;
	sphere->material = material;
	return (sphere);
}

char			*sphere_to_string(const t_sphere *sphere)
{
	char	*str;
	char	*position;

	position = vec3_to_string(&sphere->position);

	asprintf(&str, "sphere(\n"
		"   position: %s,\n"
		"   radius: %f,\n"
		"   material: %s\n"
		")",
		position,
		sphere->radius,
		sphere->material->name);

	free(position);

	return (str);
}

t_plane			*create_plane(const t_vec3 *position, const t_vec3 *normal, t_material *material)
{
	t_plane		*plane;

	plane = (t_plane*)calloc(1, sizeof(t_plane));
	vec3_copy(&plane->position, position);
	vec3_copy(&plane->normal, normal);
	plane->material = material;
	return (plane);
}

char			*plane_to_string(const t_plane *plane)
{
	char	*str;
	char	*position;
	char	*normal;

	position = vec3_to_string(&plane->position);
	normal = vec3_to_string(&plane->normal);

	asprintf(&str, "plane(\n"
		"   position: %s,\n"
		"   normal: %s,\n"
		"   material: %s\n"
		")",
		position,
		normal,
		plane->material->name);

	free(position);

	return (str);
}

t_cylinder		*create_cylinder(const t_vec3 *position, const t_vec3 *axis, float radius, t_material *material)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)calloc(1, sizeof(t_cylinder));
	vec3_copy(&cylinder->position, position);
	vec3_copy(&cylinder->axis, axis);
	cylinder->radius = radius;
	cylinder->material = material;
	return (cylinder);
}

t_cone			*create_cone(const t_vec3 *position, const t_vec3 *axis, float radius, float height, t_material *material)
{
	t_cone	*cone;

	cone = (t_cone*)calloc(1, sizeof(t_cone));
	vec3_copy(&cone->position, position);
	vec3_copy(&cone->axis, axis);
	cone->radius = radius;
	cone->height = height;
	cone->material = material;
	return (cone);
}

t_object		*create_object(const char *name, t_shape shape_type, void *shape)
{
	t_object	*object;

	object = (t_object*)calloc(1, sizeof(t_object));
	object->name = ft_strdup(name);
	object->type = shape_type;
	object->shape = shape;
	return (object);
}

char			*object_to_string(const t_object *object)
{
	char	*str;
	
	if (object->type == SPHERE)
		str = sphere_to_string(object->shape);
	else if (object->type == PLANE)
		str = plane_to_string(object->shape);
	else
		asprintf(&str, "No printer available for this type.");

	return (str);
}
