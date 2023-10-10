/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:29:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 22:08:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_player_map(t_data *d, int color)
{
	int	start;
	int	end;

	end = MMH / 2 -2;
	while (end <= MMH / 2 + 2)
	{
		start = MMW / 2 - 2;
		while (start <= MMW / 2 + 2)
			pixel_to_map(d, start++, end, color);
		end++;
	}
	pixel_to_map(d, MMW / 2, MMH / 2, BLUE);
}

void	draw_map(t_data *d)
{
	int	x;
	int	y;

	bg_map(d);
	y = 0;
	while (y < d->lns)
	{
		x = 0;
		while (x < d->cols)
		{
			if (d->map[y][x] == '1')
				draw_square(d, (x * TSM) - d->setx, (y * TSM) - d->sety, BLACK);
			if (d->map[y][x] == '0' || d->map[y][x] == 'E' ||
				d->map[y][x] == 'N' || d->map[y][x] == 'W' ||
				d->map[y][x] == 'S')
				draw_square(d, (x * TSM) - d->setx, (y * TSM) - d->sety,
					d->c.fl_color);
			if (d->map[y][x] == 'D')
				draw_square(d, (x * TSM) - d->setx, (y * TSM) - d->sety, BLUE);
			x++;
		}
		y++;
	}
	draw_player_map(d, 0x00FF00);
}
