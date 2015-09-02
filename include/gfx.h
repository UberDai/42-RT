/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/07 20:17:38 by amaurer           #+#    #+#             */
/*   Updated: 2015/09/02 20:18:38 by amaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <mlx.h>
# include "rt.h"
# include "vec3.h"

# define COLOR_NONE		-1
# define COLOR_BLACK	0
# define COLOR_WHITE	0xffffff
# define COLOR_RED		0xff0000
# define COLOR_GREEN	0x00ff00
# define COLOR_BLUE		0x0000ff

# define KEY_ESCAPE		53

typedef struct			s_color
{
	double				r;
	double				g;
	double				b;
	int					hex;
}						t_color;

struct					s_gfx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					width;
	int					height;
	int					bpp;
	int					line_size;
	int					endian;
};

void					draw_pixel(t_gfx *gfx, int x, int y, int color);
void					draw_line(t_gfx *gfx, t_vec3 *vector1, t_vec3 *vector2,
	int color);
void					draw_line_gradient(t_gfx *gfx, t_vec3 *vector1,
	t_vec3 *vector2, t_color **colors);
void					draw_rect(t_gfx *gfx, t_vec3 *vector,
	unsigned int size[], int color);
void					draw_filled_rect(t_gfx *gfx, t_vec3 *vector,
	unsigned int size[], int color);
void					mlx_update(t_gfx *gfx);
void					mlx_initialize(t_gfx *g);
void					mlx_hooks_init(t_gfx *gfx);
void					vector_swap(t_vec3 **a, t_vec3 **b);
t_vec3					*create_vector(int x, int y, int z);

t_color					*color_get_interval(t_color *color1, t_color *color2,
	int divisor);
t_color					*color_make(int hex);
t_color					*color_make_rgb(double r, double g, double b);
void					color_add(t_color *color, t_color *alter);
int						color_get_hex(int r, int g, int b);
void					color_sub(t_color *color, t_color *alter);
void					colors_swap(t_color **colors);
void					color_divide(t_color *color, int divisor);
void					color_mult(t_color *color, int mult);

int						die(const char *message);

#endif
