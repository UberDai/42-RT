/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 20:52:00 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/01 21:09:07 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include <libft.h>
#include <stdlib.h>

t_sphere		*create_sphere(const t_vec3 *position, float radius, t_material *material)
{
	t_sphere	*sphere;

	sphere = calloc(1, sizeof(t_sphere));
	vec3_copy(&sphere->position, position);
	sphere->radius = radius;
	sphere->material = material;

	return (sphere);
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
