/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_projectile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:22:38 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/06 15:14:22 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	check_horizontal_hit(t_data *d)
{
	bool	is_hit;

	is_hit = false;
	if (d->plasma.angle > PI)
	{
		d->plasma.dir_y = ((int)d->plasma.y / TS) * TS - 0.0001;
		d->plasma.dir_x = (d->plasma.y - d->plasma.dir_y)
			* (-1 / tan(d->plasma.angle)) + d->px;
		d->plasma.stepy = -1;
		d->plasma.stepx = -(1 / tan(d->plasma.angle));
	}
	else
	{
		d->plasma.dir_y = ((int)d->plasma.y / TS) * TS + TS;
		d->plasma.dir_x = (d->plasma.y - d->plasma.dir_y)
			* (-1 / tan(d->plasma.angle)) + d->px;
		d->plasma.stepy = 1;
		d->plasma.stepx = (1 / tan(d->plasma.angle));
	}
	if (d->plasma.angle == 0 || d->plasma.angle == PI)
	{
		d->plasma.dir_x = d->plasma.x;
		d->plasma.dir_y = d->plasma.y;
	}
	check_horizontal_gridline(d, is_hit);
}

void	check_horizontal_gridline(t_data *d, bool is_hit)
{
	while (is_hit == false)
	{
		d->plasma.mcx = d->plasma.dir_x / TS;
		d->plasma.mcy = d->plasma.dir_y / TS;
		if (d->plasma.mcx > d->cols)
			d->plasma.mcx = d->cols;
		if (d->plasma.mcy < 0)
			d->plasma.mcy = 0;
		else if (d->plasma.mcy >= d->lns)
			d->plasma.mcy = d->lns - 1;
		if (d->plasma.mcx < 0)
			d->plasma.mcx = 0;
		if (d->map[d->plasma.mcy][d->plasma.mcx] == '1' ||
			(d->map[d->plasma.mcy][d->plasma.mcx] == 'D' ||
			d->map[d->plasma.mcy][d->plasma.mcx] == 0))
			is_hit = true;
		else
		{
			d->plasma.dir_x += d->plasma.stepx;
			d->plasma.dir_y += d->plasma.stepy;
		}
	}
	d->plasma.h_x = d->plasma.dir_x;
	d->plasma.h_y = d->plasma.dir_y;
}

void	check_vertical_hit(t_data *d)
{
	bool	is_hit;

	is_hit = false;
	if (d->plasma.angle >= PI / 2 && d->plasma.angle <= 3 * PI / 2)
	{
		d->plasma.dir_x = ((int)d->plasma.x / TS) * TS - 0.0001;
		d->plasma.dir_y = (d->plasma.x - d->plasma.dir_x)
			* -tan(d->plasma.angle) + d->plasma.y;
		d->plasma.stepx = -1;
		d->plasma.stepy = -tan(d->plasma.angle);
	}
	else
	{
		d->plasma.dir_x = ((int)d->plasma.x / TS) * TS + TS;
		d->plasma.dir_y = (d->plasma.x - d->plasma.dir_x)
			* -tan(d->plasma.angle) + d->plasma.y;
		d->plasma.stepx = 1;
		d->plasma.stepy = tan(d->plasma.angle);
	}
	if (d->plasma.angle == PI / 2 || d->plasma.angle == (3 * PI) / 2)
	{
		d->plasma.dir_x = d->plasma.x;
		d->plasma.dir_y = d->plasma.y;
	}
	check_vertical_gridline(d, is_hit);
}

void	check_vertical_gridline(t_data *d, bool is_hit)
{
	while (is_hit == false)
	{
		d->plasma.mcx = d->plasma.dir_x / TS;
		d->plasma.mcy = d->plasma.dir_y / TS;
		if (d->plasma.mcy < 0)
			d->plasma.mcy = 0;
		else if (d->plasma.mcy >= d->lns)
			d->plasma.mcy = d->lns - 1;
		if (d->plasma.mcx < 0)
			d->plasma.mcx = 0;
		if (d->map[d->plasma.mcy][d->plasma.mcx] == '1' ||
		d->map[d->plasma.mcy][d->plasma.mcx] == 0 ||
			(d->map[d->plasma.mcy][d->plasma.mcx] == 'D'))
			is_hit = true;
		else
		{
			d->plasma.dir_x += d->plasma.stepx;
			d->plasma.dir_y += d->plasma.stepy;
		}
	}
	d->plasma.v_x = d->plasma.dir_x;
	d->plasma.v_y = d->plasma.dir_y;
}

void	dda_projectile(t_data *d)
{
	d->plasma.mcx = (int)d->plasma.x / TS;
	d->plasma.mcy = (int)d->plasma.y / TS;
	check_horizontal_hit(d);
	d->plasma.len_h = sqrt(pow(d->plasma.h_x - d->plasma.x, 2)
			+ pow(d->plasma.h_y - d->plasma.y, 2));
	check_vertical_hit(d);
	d->plasma.len_v = sqrt(pow(d->plasma.v_x - d->plasma.x, 2)
			+ pow(d->plasma.v_y - d->plasma.y, 2));
	if (d->plasma.len_h > d->plasma.len_v)
	{
		d->plasma.dist = d->plasma.len_v;
		d->plasma.dir_x = d->plasma.v_x;
		d->plasma.dir_y = d->plasma.v_y;
	}
	else
	{
		d->plasma.dist = d->plasma.len_h;
		d->plasma.dir_x = d->plasma.h_x;
		d->plasma.dir_y = d->plasma.h_y;
	}
}
