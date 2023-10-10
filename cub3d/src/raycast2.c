/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:55:04 by alexfern          #+#    #+#             */
/*   Updated: 2023/09/29 19:00:56 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	wall_check_v(t_data *d, bool is_wall)
{
	while (is_wall == false)
	{
		d->r.mapcx = d->r.rayx / TS;
		d->r.mapcy = d->r.rayy / TS;
		if (d->r.mapcy < 0)
			d->r.mapcy = 0;
		else if (d->r.mapcy >= d->lns)
			d->r.mapcy = d->lns - 1;
		if (d->r.mapcx < 0)
			d->r.mapcx = 0;
		if (d->map[d->r.mapcy][d->r.mapcx] == '1' ||
			d->map[d->r.mapcy][d->r.mapcx] == 'D' ||
			d->map[d->r.mapcy][d->r.mapcx] == 0)
			is_wall = true;
		else
		{
			d->r.rayx += d->r.stepx;
			d->r.rayy += d->r.stepy;
		}
	}
	d->r.v_rayx = d->r.rayx;
	d->r.v_rayy = d->r.rayy;
}

void	calc_inter_v(t_data *d)
{
	bool	is_wall;

	is_wall = false;
	if (d->r.angle >= PI / 2 && d->r.angle <= 3 * PI / 2)
	{
		d->r.rayx = ((int)d->px / TS) * TS - 0.0001;
		d->r.rayy = (d->px - d->r.rayx) * -tan(d->r.angle) + d->py;
		d->r.stepx = -TS;
		d->r.stepy = d->r.stepx * tan(d->r.angle);
	}
	else
	{
		d->r.rayx = ((int)d->px / TS) * TS + TS;
		d->r.rayy = (d->px - d->r.rayx) * -tan(d->r.angle) + d->py;
		d->r.stepx = TS;
		d->r.stepy = d->r.stepx * tan(d->r.angle);
	}
	if (d->r.angle == PI / 2 || d->r.angle == (3 * PI) / 2)
	{
		d->r.rayx = d->px;
		d->r.rayy = d->py;
	}
	wall_check_v(d, is_wall);
}
