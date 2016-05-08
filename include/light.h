/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 07:34:22 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/25 07:58:53 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIGHT_H
# define _LIGHT_H

# include "vec3.h"

typedef enum	e_light
{
	POINT
}				e_light;

typedef struct	s_light
{
	e_light		type;
	t_vec3		position;
	float		intensity;
	t_vec3		color;
}				t_light;

t_light	*create_light(const t_vec3 *position, float intensity, const t_vec3 *color);
char	*light_to_string(const t_light *light);

#endif
