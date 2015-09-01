/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 21:04:30 by amaurer           #+#    #+#             */
/*   Updated: 2015/07/07 22:06:36 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "gfx.h"

void	mlx_initialize(t_gfx *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		die("Count not init mlx");
	if (!(g->win = mlx_new_window(g->mlx, g->width, g->height, "FDF")))
		die("Could not create the window.");
	if (!(g->img = mlx_new_image(g->mlx, g->width, g->height)))
		die("Could not create the image.");
	g->data = mlx_get_data_addr(g->img, &g->bpp, &g->line_size, &g->endian);
	if (!g->data)
		die("Could not get image data.");
	mlx_hooks_init(g);
	mlx_loop(g->mlx);
}

void	mlx_update(t_gfx *gfx)
{
	mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img, 0, 0);
}
