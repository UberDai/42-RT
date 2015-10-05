/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 19:00:23 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/01 19:04:41 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_blend_overlay(t_vec3 *dest, const t_vec3 *src)
{
	if (dest->x < 0.5f)
		dest->x = 2 * dest->x * src->x;
	else
		dest->x = 1.0f - 2.0f * (1.0f - dest->x) * (1.0f - src->x);

	if (dest->y < 0.5f)
		dest->y = 2 * dest->y * src->y;
	else
		dest->y = 1.0f - 2.0f * (1.0f - dest->y) * (1.0f - src->y);

	if (dest->z < 0.5f)
		dest->z = 2 * dest->z * src->z;
	else
		dest->z = 1.0f - 2.0f * (1.0f - dest->z) * (1.0f - src->z);
}
