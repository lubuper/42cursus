/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:59:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/05 22:11:38 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	move_player(t_data *d)
{
	if (d->kflag.shift == 1)
		d->kflag.speed = 7;
	if (d->kflag.backwards == 1)
		move_backwards(d);
	if (d->kflag.forward == 1)
		move_forward(d);
	look(d);
	if (d->kflag.strafe_l == 1)
		strafe_left(d, PI / 2);
	if (d->kflag.strafe_r == 1)
		strafe_right(d, PI / 2);
	if (d->kflag.forward || d->kflag.backwards || d->kflag.strafe_l
		|| d->kflag.strafe_r)
		d->counter++;
	if (d->counter == 36)
		d->counter = 0;
}

void	w_move(t_data *d)
{
	if (d->kflag.fire == 1)
	{
		gun_animation(d);
		d->counter = 0;
	}
	else if (d->counter >= 0 && d->counter < 9)
		w_bob(d, d->wi, 473 + d->counter, 452 + d->counter);
	else if (d->counter > 8 && d->counter < 18)
		w_bob(d, d->wi, 491 - d->counter, 470 - d->counter);
	else if (d->counter > 17 && d->counter < 27)
		w_bob(d, d->wi, 455 + d->counter, 434 + d->counter);
	else if (d->counter > 26 && d->counter < 36)
		w_bob(d, d->wi, 509 - d->counter, 488 - d->counter);
}

void	w_bob(t_data *d, t_img img, int x1, int y1)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	color = 0;
	while (x < img.width)
	{
		y = 1;
		while (y <= img.height)
		{
			color = get_colors(&img, x, y);
			if (color != 0xFF00FF)
				pixel_to_scr(d, x + x1, y + y1, color);
			y++;
		}
		x++;
	}
}
