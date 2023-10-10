/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:09:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 15:34:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_walls(t_data *d)
{
	int		x;
	float	inc_a;

	x = 0;
	inc_a = (60.0 / WIDTH) * DR;
	d->r.angle = (d->pa - (30 * DR));
	while (x < WIDTH)
	{
		if (d->r.angle > 2 * PI)
			d->r.angle -= (2 * PI);
		else if (d->r.angle < 0)
			d->r.angle += (2 * PI);
		dda_draw(d, x);
		x++;
		d->r.angle += inc_a;
	}
}

t_img	get_image(t_data *d, char wall)
{
	if (wall == 'N')
		return (d->nwtex);
	else if (wall == 'S')
		return (d->swtex);
	else if (wall == 'W')
		return (d->wwtex);
	else if (wall == 'E')
		return (d->ewtex);
	else
		return (d->door);
}

void	draw_vline(t_data *d, int x, char wall)
{
	int		y;
	int		x_tex;
	int		y_tex;
	t_img	wall_tex;

	wall_tex = get_image(d, wall);
	x_tex = get_tex_x(d, wall);
	y = (HEIGHT / 2) - (d->r.wall_h / 2);
	if (y < 0)
		y = 0;
	while (y < (HEIGHT / 2 + d->r.wall_h / 2))
	{
		if (y >= HEIGHT)
			break ;
		y_tex = (int)((y - ((HEIGHT / 2) - (d->r.wall_h / 2)))
				/ (d->r.wall_h / TS));
		pixel_to_scr(d, x, y, shadecolor(d, get_colors(&wall_tex, x_tex, y_tex),
				d->fow));
		y++;
	}
}

int	get_tex_x(t_data *d, char wall)
{
	if (wall == 'N' || wall == 'S')
		return ((int)d->r.rayx % TS);
	else if (wall == 'W' || wall == 'E')
		return ((int)d->r.rayy % TS);
	else
	{
		if (d->r.len_h < d->r.len_v)
			return ((int)d->r.rayx % TS);
		else
			return ((int)d->r.rayy % TS);
	}
}

int	shadecolor(t_data *d, int color, float shader)
{
	int	r;
	int	g;
	int	b;

	d->c.f_r = color >> 16 & 0xFF;
	d->c.f_g = color >> 8 & 0xFF;
	d->c.f_b = color & 0xFF;
	r = ((color >> 16) & 0xFF) * (shader);
	g = ((color >> 8) & 0xFF) * (shader);
	b = (color & 0xFF) * (shader);
	if (r > d->c.f_r)
		r = d->c.f_r;
	if (g > d->c.f_g)
		g = d->c.f_g;
	if (b > d->c.f_b)
		b = d->c.f_b;
	color = (r << 16);
	color += (g << 8);
	color += b;
	return (color);
}
