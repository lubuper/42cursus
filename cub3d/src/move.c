/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:59:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/09/20 14:21:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_player(t_data *d)
{
	float	right_angle;

	right_angle = PI / 2;
	if (d->kflag.backwards == 1)
		move_backwards(d);
	if (d->kflag.forward == 1)
		move_forward(d);
	if (d->kflag.look_l == 1)
	{
		d->pa -= DR;
		if (d->pa <= 0)
			d->pa += 2 * PI;
	}
	if (d->kflag.look_r == 1)
	{
		d->pa += DR;
		if (d->pa > 2 * PI)
			d->pa -= 2 * PI;
	}
	if (d->kflag.strafe_l == 1)
		strafe_left(d, right_angle);
	if (d->kflag.strafe_r == 1)
		strafe_right(d, right_angle);
}

void	move_forward(t_data *d)
{
	d->py += (SPEED * d->pdy);
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->py -= (SPEED * d->pdy);
	d->px += (SPEED * d->pdx);
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->px -= (SPEED * d->pdx);
}

void	move_backwards(t_data *d)
{
	d->py -= (SPEED * d->pdy);
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->py += (SPEED * d->pdy);
	d->px -= (SPEED * d->pdx);
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->px += (SPEED * d->pdx);
}

void	strafe_left(t_data *d, float right_angle)
{
	d->py -= (SPEED * (sin(d->pa + right_angle)));
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->py += (SPEED * (sin(d->pa + right_angle)));
	d->px -= (SPEED * (cos(d->pa + right_angle)));
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->px += (SPEED * (cos(d->pa + right_angle)));
}

void	strafe_right(t_data *d, float right_angle)
{
	d->py -= (SPEED * (sin(d->pa - right_angle)));
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->py += (SPEED * (sin(d->pa - right_angle)));
	d->px -= (SPEED * (cos(d->pa - right_angle)));
	if (d->map[(int)d->py / TS][(int)d->px / TS] == '1'
		|| d->map[(int)d->py / TS][(int)d->px / TS] == ' ')
		d->px += (SPEED * (cos(d->pa - right_angle)));
}
