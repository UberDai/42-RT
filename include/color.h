/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 19:01:19 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/01 19:04:19 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COLOR_H
# define _COLOR_H

# include "vec3.h"

void	color_blend_overlay(t_vec3 *dest, const t_vec3 *src);

#endif
