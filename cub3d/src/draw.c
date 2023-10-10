/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:09:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/09/20 17:53:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	else
		return (d->ewtex);
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
		pixel_to_scr(d, x, y, get_colors(&wall_tex, x_tex, y_tex));
		y++;
	}
}

int	get_tex_x(t_data *d, char wall)
{
	if (wall == 'N' || wall == 'S')
		return ((int)d->r.rayx % TS);
	else
		return ((int)d->r.rayy % TS);
}
