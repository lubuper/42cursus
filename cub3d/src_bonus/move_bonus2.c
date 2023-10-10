/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:04:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 16:15:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	pvtocollision(t_data *d)
{
	if (d->map[(int)(d->py / TS + PVM)][(int)d->px / TS] == '1'
		|| d->map[(int)(d->py / TS - PVM)][(int)d->px / TS] == '1'
		|| d->map[(int)(d->py / TS - PVM)][(int)(d->px / TS - PVM)] == '1'
		|| d->map[(int)(d->py / TS - PVM)][(int)(d->px / TS + PVM)] == '1'
		|| d->map[(int)(d->py / TS + PVM)][(int)(d->px / TS + PVM)] == '1'
		|| d->map[(int)(d->py / TS + PVM)][(int)(d->px / TS - PVM)] == '1')
		return (1);
	else if ((d->map[(int)(d->py / TS + PVM)][(int)d->px / TS] == 'D'
		|| d->map[(int)(d->py / TS - PVM)][(int)d->px / TS] == 'D'
		|| d->map[(int)(d->py / TS - PVM)][(int)(d->px / TS - PVM)] == 'D'
		|| d->map[(int)(d->py / TS - PVM)][(int)(d->px / TS + PVM)] == 'D'
		|| d->map[(int)(d->py / TS + PVM)][(int)(d->px / TS + PVM)] == 'D'
		|| d->map[(int)(d->py / TS + PVM)][(int)(d->px / TS - PVM)] == 'D'))
		return (1);
	return (0);
}

void	move_forward(t_data *d)
{
	d->py += (d->kflag.speed * d->pdy);
	if (pvtocollision(d))
		d->py -= (d->kflag.speed * d->pdy);
	d->px += (d->kflag.speed * d->pdx);
	if (pvtocollision(d))
		d->px -= (d->kflag.speed * d->pdx);
}

void	move_backwards(t_data *d)
{
	d->py -= (d->kflag.speed * d->pdy);
	if (pvtocollision(d))
		d->py += (d->kflag.speed * d->pdy);
	d->px -= (d->kflag.speed * d->pdx);
	if (pvtocollision(d))
		d->px += (d->kflag.speed * d->pdx);
}

void	strafe_left(t_data *d, float right_angle)
{
	d->kflag.speed = 3;
	d->py -= (d->kflag.speed * (sin(d->pa + right_angle)));
	if (pvtocollision(d))
		d->py += (d->kflag.speed * (sin(d->pa + right_angle)));
	d->px -= (d->kflag.speed * (cos(d->pa + right_angle)));
	if (pvtocollision(d))
		d->px += (d->kflag.speed * (cos(d->pa + right_angle)));
}

void	strafe_right(t_data *d, float right_angle)
{
	d->kflag.speed = 3;
	d->py -= (d->kflag.speed * (sin(d->pa - right_angle)));
	if (pvtocollision(d))
		d->py += (d->kflag.speed * (sin(d->pa - right_angle)));
	d->px -= (d->kflag.speed * (cos(d->pa - right_angle)));
	if (pvtocollision(d))
		d->px += (d->kflag.speed * (cos(d->pa - right_angle)));
}
