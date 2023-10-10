/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:06:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 22:08:22 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	pixel_to_map(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->mm.addr + (y * d->mm.line_len + x * (d->mm.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *d, int x, int y, int color)
{
	int	i;
	int	o;

	i = 0;
	while (i < TSM && (y + i) < MMW && y >= 0)
	{
		o = 0;
		while (o < TSM && (x + o) < MMH && x >= 0)
		{
			pixel_to_map(d, x + o, y + i, color);
			o++;
		}
		i++;
	}
}

void	bg_map(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < MMH)
	{
		x = 0;
		while (x < MMW)
			pixel_to_map(d, x++, y, BLACK);
		y++;
	}
	d->setx = player_distx(d);
	d->sety = player_disty(d);
}

int	player_distx(t_data *d)
{
	int	result;

	result = (((d->px / TS) * TSM) - (MMW / 2));
	return (result);
}

int	player_disty(t_data *d)
{
	int	result;

	result = (((d->py / TS) * TSM) - (MMH / 2));
	return (result);
}
