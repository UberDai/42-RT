/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:11:32 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/14 00:15:32 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "vec3.h"

int		die(const char *message);
int		vec3_to_color(t_vec3 const *color);
t_vec3	*color_to_vec3(t_vec3 *vec, int color);

#endif
