/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:43:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 18:25:49 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	draw_border_top(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < 16)
	{
		x = 0;
		while (x < MMW)
			pixel_to_map(d, x++, y, BLACK);
		y++;
	}
}

void	draw_border_left(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < MMH)
	{
		x = 0;
		while (x < 16)
			pixel_to_map(d, x++, y, BLACK);
		y++;
	}
}

void	draw_border_right(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < MMH)
	{
		x = MMW - 16;
		while (x < MMW)
			pixel_to_map(d, x++, y, BLACK);
		y++;
	}
}

void	draw_border_bottom(t_data *d)
{
	int	x;
	int	y;

	y = MMH - 16;
	while (y < MMH)
	{
		x = 0;
		while (x < MMW)
			pixel_to_map(d, x++, y, BLACK);
		y++;
	}
}

void	draw_border(t_data *d)
{
	draw_border_top(d);
	draw_border_left(d);
	draw_border_right(d);
	draw_border_bottom(d);
}
