/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:50:07 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/07 22:22:07 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <stdlib.h>
#include "rt.h"

extern t_rt	rt;

int			hook_key(int keycode, t_rt *rt)
{
	(void)rt;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int			hook_expose(t_rt *rt)
{
	draw(rt);
	return (0);
}

void		mlx_hooks_init(t_gfx *gfx)
{
	mlx_key_hook(gfx->win, hook_key, &rt);
	mlx_expose_hook(gfx->win, hook_expose, &rt);
}
