/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 20:09:43 by amaurer           #+#    #+#             */
/*   Updated: 2015/10/05 19:11:55 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <ftlst.h>
# include "scene.h"
# include <stdio.h>

# define COLOR_NONE	-1

typedef struct s_gfx	t_gfx;

typedef struct			s_rt
{
	int					rendered;
	int					width;
	int					height;
	float				aspect;
	t_gfx				*gfx;
	t_scene				*scene;
}						t_rt;

void					render(t_rt *rt);

#endif
