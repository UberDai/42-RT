/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 22:11:32 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 18:53:53 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdlib.h>
# include <libft.h>
# include "vec3.h"

# define QUADRATIC_NONE	0
# define QUADRATIC_ONE	1
# define QUADRATIC_TWO	2
# define NEW(X)			(X*)malloc(sizeof(X));

int		die(const char *message);
int		vec3_to_color(t_vec3 const *color);
t_vec3	*color_to_vec3(t_vec3 *vec, int color);
float	select_closest_hit(float hit1, float hit2);
int		solve_quadratic(float a, float b, float c, float results[2]);
void	color_clamp(t_vec3 *color);

#endif
