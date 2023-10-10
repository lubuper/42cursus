/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:22:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/09/29 18:53:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	determine_wall(t_data *d)
{
	char	wall;

	if (d->r.len_h > d->r.len_v)
	{
		d->r.ray_d = d->r.len_v;
		d->r.rayx = d->r.v_rayx;
		d->r.rayy = d->r.v_rayy;
		if (d->r.angle > PI / 2 && d->r.angle < (3 * PI) / 2)
			wall = 'W';
		else
			wall = 'E';
	}
	else
	{
		d->r.ray_d = d->r.len_h;
		d->r.rayx = d->r.h_rayx;
		d->r.rayy = d->r.h_rayy;
		if (d->r.angle > PI)
			wall = 'N';
		else
			wall = 'S';
	}
	return (wall);
}

void	dda_draw(t_data *d, int x)
{
	char	wall;
	float	ca;

	ca = 0.0;
	d->r.mapcx = (int)d->px / TS;
	d->r.mapcy = (int)d->py / TS;
	calc_inter_h(d);
	d->r.len_h = sqrt(pow(d->r.h_rayx - d->px, 2)
			+ pow(d->r.h_rayy - d->py, 2));
	calc_inter_v(d);
	d->r.len_v = sqrt(pow(d->r.v_rayx - d->px, 2)
			+ pow(d->r.v_rayy - d->py, 2));
	wall = determine_wall(d);
	calc_angle(d, ca);
	d->r.wall_h = (int)(HEIGHT * 99 / d->r.ray_d);
	draw_vline(d, x, wall);
}

void	calc_angle(t_data *d, float ca)
{
	ca = d->pa - d->r.angle;
	if (ca < 0)
		ca += 2 * PI;
	else if (ca > 2 * PI)
		ca -= 2 * PI;
	d->r.ray_d *= cos(ca);
	if (d->r.ray_d <= 0)
		d->r.ray_d = 1;
}

void	wall_check_h(t_data *d, bool is_wall)
{
	while (is_wall == false)
	{
		d->r.mapcx = d->r.rayx / TS;
		d->r.mapcy = d->r.rayy / TS;
		if (d->r.mapcx > d->cols)
			d->r.mapcx = d->cols;
		if (d->r.mapcy < 0)
			d->r.mapcy = 0;
		else if (d->r.mapcy >= d->lns)
			d->r.mapcy = d->lns - 1;
		if (d->r.mapcx < 0)
			d->r.mapcx = 0;
		if (d->map[d->r.mapcy][d->r.mapcx] == '1' ||
		d->map[d->r.mapcy][d->r.mapcx] == 0)
			is_wall = true;
		else
		{
			d->r.rayx += d->r.stepx;
			d->r.rayy += d->r.stepy;
		}
	}
	d->r.h_rayx = d->r.rayx;
	d->r.h_rayy = d->r.rayy;
}

void	calc_inter_h(t_data *d)
{
	bool	is_wall;

	is_wall = false;
	if (d->r.angle > PI)
	{
		d->r.rayy = ((int)d->py / TS) * TS - 0.0001;
		d->r.rayx = (d->py - d->r.rayy) * (-1 / tan(d->r.angle)) + d->px;
		d->r.stepy = -TS;
		d->r.stepx = d->r.stepy * (1 / tan(d->r.angle));
	}
	else
	{
		d->r.rayy = ((int)d->py / TS) * TS + TS;
		d->r.rayx = (d->py - d->r.rayy) * (-1 / tan(d->r.angle)) + d->px;
		d->r.stepy = TS;
		d->r.stepx = d->r.stepy * (1 / tan(d->r.angle));
	}
	if (d->r.angle == 0 || d->r.angle == PI)
	{
		d->r.rayx = d->px;
		d->r.rayy = d->py;
	}
	wall_check_h(d, is_wall);
}
