/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:15:48 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 16:21:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	door_action(t_data *d)
{
	static int	close_timer;
	static int	x;
	static int	y;

	if (close_timer == 0 && d->kflag.open == 1)
		check_door_loc(d, &x, &y);
	if (d->kflag.open == 1 && x != 0 && y != 0)
		close_timer++;
	if (close_timer == 1)
		d->dmap[y][x] = '0';
	else if (close_timer == 45)
	{
		d->kflag.open = 0;
		if (((int)d->py / TS != y || (int)d->px / TS != x))
		{
			d->dmap[y][x] = 'D';
			close_timer = 0;
			x = 0;
			y = 0;
		}
	}
}

void	check_door_loc(t_data *d, int *x, int *y)
{
	if (d->dmap[(int)d->py / TS + 1][(int)d->px / TS] == 'D')
	{
		*x = (int)d->px / TS;
		*y = (int)d->py / TS + 1;
	}
	if (d->dmap[(int)d->py / TS][(int)d->px / TS + 1] == 'D')
	{
		*x = (int)d->px / TS + 1;
		*y = (int)d->py / TS;
	}
	if (d->dmap[(int)d->py / TS][(int)d->px / TS - 1] == 'D')
	{
		*x = (int)d->px / TS - 1;
		*y = (int)d->py / TS;
	}
	if (d->dmap[(int)d->py / TS - 1][(int)d->px / TS] == 'D')
	{
		*x = (int)d->px / TS;
		*y = (int)d->py / TS - 1;
	}
}

void	shoot(t_data *d)
{
	static int	c;
	static int	pre;
	static int	y;

	if (pre == 0)
	{
		y = HEIGHT / 2;
		d->plasma.speed = 3;
		d->plasma.y = d->py;
		d->plasma.x = d->px;
		d->plasma.angle = d->pa;
		pre = 1;
	}
	if (c == 7)
	{
		dda_projectile(d);
		projectile_draw(d, WIDTH / 2, y--);
	}
	c++;
	if (c == 22)
	{
		c = 0;
		d->kflag.fire = 0;
		pre = 0;
	}
}

void	projectile_draw(t_data *d, int x1, int y1)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	color = 0;
	while (x < d->ptl.width)
	{
		y = 1;
		while (y < d->ptl.height)
		{
			color = get_colors(&d->ptl, x, y);
			if (color != 0xFF00FF)
				pixel_to_scr(d, x + x1, y + y1, color);
			y++;
		}
		x++;
	}
}

void	gun_animation(t_data *d)
{
	static int	pc;

	if (pc < 2)
		w_bob(d, d->w2, 565, 520);
	else if (pc > 1 && pc < 3)
		w_bob(d, d->w3, 565, 520);
	else if (pc > 2 && pc < 7)
		w_bob(d, d->w3, 565, 520);
	else if (pc > 6 && pc < 21)
		w_bob(d, d->wi, 473, 432 + pc);
	pc++;
	if (pc == 21)
		pc = 0;
}
