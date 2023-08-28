/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:09:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 19:24:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	draw_table(t_data *d)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	draw_floor_ceil(d);
	put_grid(d);
	return (0);
}

void	put_grid(t_data *d)
{
	int		xdist;
	int		ydist;

	d->y = 0;
	while (d->y < d->lines)
	{
		d->x = 0;
		while (d->x < (int)ft_strlen(d->map[d->y]))
		{
			if (d->map[d->y][d->x] == '1')
			{
				ydist = d->y * 10;
				while (ydist < (d->y + 1) * 10)
				{
					xdist = d->x * 10;
					while (xdist < (d->x + 1) * 10)
					{
						mlx_pixel_put(d->mlx, d->win, (d->x + xdist), (d->y + ydist), 0xFFFFFF);
						xdist++;
					}
					xdist = 0;
					ydist++;
				}
			}
			else if (d->map[d->y][d->x] == '0' || d->map[d->y][d->x] == d->d)
			{
				ydist = d->y * 10;
				while (ydist < (d->y + 1) * 10)
				{
					xdist = d->x * 10;
					while (xdist < (d->x + 1) * 10)
					{
						mlx_pixel_put(d->mlx, d->win, (d->x + xdist), (d->y + ydist), 0x000000);
						xdist++;
					}
					xdist = 0;
					ydist++;
				}
			}
			d->x++;
		}
		d->y++;
	}
	ydist = (d->py * 10);
	while (ydist < (d->py + 1) * 10)
	{
		xdist = (d->px * 10);
		while (xdist < (d->px + 1) * 10)
		{
			mlx_pixel_put(d->mlx, d->win, (d->px + xdist), (d->py + ydist), d->i.floor_colour);
			xdist++;
		}
		xdist = 0;
		ydist++;
	}
}
