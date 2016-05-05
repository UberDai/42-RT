/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:33:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:26:09 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "util.h"

void		*parse_vec3(char **tokens)
{
	t_vec3	*vec;

	vec = vec3_zero();

	if (tokens[0] != NULL)
	{
		vec->x = ft_atoi(tokens[0]);

		if (tokens[1] != NULL)
		{
			vec->y = ft_atoi(tokens[1]);

			if (tokens[2] != NULL)
				vec->z = ft_atoi(tokens[2]);
		}
	}

	return (vec);
}
