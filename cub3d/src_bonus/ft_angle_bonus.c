/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubu <lubu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:29:59 by alex              #+#    #+#             */
/*   Updated: 2023/10/06 14:38:41 by lubu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

float	ft_angle(int nbr)
{
	if (nbr == 0)
		return (0);
	return (nbr * WIDTH / 60);
}

// N and S are switched because the way the map is drawn
void	dir_angle(t_data *d)
{
	if (d->d == 'E')
		d->pa = 0;
	else if (d->d == 'S')
		d->pa = PI / 2;
	else if (d->d == 'W')
		d->pa = PI;
	else if (d->d == 'N')
		d->pa = ((3 * PI) / 2);
}

void	mouse_move(t_data *d)
{
	int	x;
	int	y;
	int	off_x;
	int	off_y;

	x = d->mousex;
	y = d->mousey;
	mlx_mouse_get_pos(d->mlx, d->win, &d->mousex, &d->mousey);
	off_x = d->mousex - x;
	off_y = d->mousey - y;
	mouse_x(d, &off_x);
	mouse_y(d, &off_y);
}

void	mouse_x(t_data *d, int *off_x)
{
	if (d->mousex < 1)
	{
		mlx_mouse_move(d->mlx, d->win, WIDTH - 1, d->mousey);
		d->mousex = WIDTH - 1;
	}
	else if (d->mousex >= WIDTH)
	{
		mlx_mouse_move(d->mlx, d->win, 1, d->mousey);
		d->mousex = 1;
	}
	if (*off_x)
		d->pa += *off_x * 000.15 * DR;
}

void	mouse_y(t_data *d, int *off_y)
{
	if (d->mousey < 1)
	{
		mlx_mouse_move(d->mlx, d->win, d->mousex, HEIGHT - 1);
		d->mousey = HEIGHT - 1;
	}
	else if (d->mousey > HEIGHT - 1)
	{
		mlx_mouse_move(d->mlx, d->win, d->mousex, 1);
		d->mousey = 1;
	}
	(void)off_y;
}
