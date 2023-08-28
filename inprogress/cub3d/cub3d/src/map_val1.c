/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 13:00:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	valid_first_walls(t_data *d)
{
	while (d->y < d->lines)
	{
		if (d->map[d->y][0] == '1' || d->map[d->y][0] == ' ')
			d->y++;
		else
			return (0);
	}
	while (d->x < (int)ft_strlen(d->map[0]))
	{
		if (d->map[0][d->x] == '1' || d->map[d->y][0] == ' ')
			d->x++;
		else
			return (0);
	}
	d->x = 0;
	while (d->x < (int)ft_strlen(d->map[d->lines - 1]))
	{
		if (d->map[d->lines - 1][d->x] == '1' || d->map[d->y][0] == ' ')
			d->x++;
		else
			return (0);
	}
	if (!valid_remain_walls(d))
		return (0);
	return (1);
}

int	valid_remain_walls(t_data *d)
{
	d->y = 0;
	while (d->y < d->lines - 1)
	{
		if (d->map[d->y][(int)ft_strlen(d->map[d->y])] != '1')
			d->y++;
		else
			return (0);
	}
	d->y = 1;
	d->x = 1;
	while (d->y < d->lines - 1)
	{
		if (verify_conditions(d))
			d->y++;
		else
			return (0);
	}
	return (1);
}

void	treat_map(t_data *d)
{
	if (!valid_first_walls(d))
	{
		printf("Error!\nInvalid wall placement!\n");
		frees(d);
	}
	if (d->end_flag)
	{
		printf("Error\nInvalid path to .xpm texture\n");
		frees(d);
		exit(1);
	}
}

int	verify_conditions(t_data *d)
{
	while (d->x < (int)ft_strlen(d->map[d->y]))
	{
		if (d->map[d->y][d->x] == '0' && (d->map[d->y][d->x - 1] == ' '
			|| d->map[d->y][d->x + 1] == ' '))
			return (0);
		if ((d->map[d->y][d->x] == '0') && ((d->map[d->y + 1][d->x]
			&& d->map[d->y + 1][d->x] == ' ') || (d->map[d->y - 1][d->x]
			&& d->map[d->y - 1][d->x] == ' ')))
			return (0);
		if (d->map[d->y][d->x] != '1' && d->map[d->y][d->x] != d->d 
			&& d->map[d->y][d->x] != '0' && d->map[d->y][d->x])
			return (0);
		d->x++;
	}
	return (1);
}

/*void	valid_way(t_data *d, char** map, int y, int x)
{
	static int	wayout;
	static int	pickup;

	if (map[y][x] == 'E')
	{
		d->ex = x;
		d->ey = y;
		wayout = 1;
		return (0);
	}
	if (map[y][x] == 'C')
		pickup++;
	if (map[y][x] == '1' || x > d->cols || y > d->lines
			|| map[y][x] == 'V' || map[y][x] == 'M')
		return (0);
	map[y][x] = 'V';
	valid_path(d, d->mapdup, y + 1, x);
	valid_path(d, d->mapdup, y - 1, x);
	valid_path(d, d->mapdup, y, x + 1);
	valid_path(d, d->mapdup, y, x - 1);
	if (wayout == 1)
		return (1);
	else
		return (0);
}*/
