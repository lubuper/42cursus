/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:04 by lde-sous          #+#    #+#             */
/*   Updated: 2023/09/28 20:11:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	valid_first_walls(t_data *d)
{
	while (d->y < d->lns)
	{
		if ((d->map[d->y][0] == '1' || d->map[d->y][0] == ' ')
			&& (d->map[d->y][(int)ft_strlen(d->map[d->y]) - 1] == '1'
			|| d->map[d->y][(int)ft_strlen(d->map[d->y]) - 1] == ' '))
			d->y++;
		else
			return (0);
	}
	while (d->x < (int)ft_strlen(d->map[0]))
	{
		if (d->map[0][d->x] == '1' || d->map[0][d->x] == ' ')
			d->x++;
		else
			return (0);
	}
	d->x = 0;
	while (d->x < (int)ft_strlen(d->map[d->lns - 1]))
	{
		if (d->map[d->lns - 1][d->x] == '1' || d->map[d->lns - 1][d->x] == ' ')
			d->x++;
		else
			return (0);
	}
	return (1);
}

int	valid_remain_walls(t_data *d)
{
	d->y = 1;
	while (d->y < d->lns - 1)
	{
		d->x = 1;
		if (verify_conditions(d))
			d->y++;
		else
			return (0);
	}
	return (1);
}

void	treat_map(t_data *d)
{
	int	x;
	int	len;

	x = 0;
	len = 0;
	while (x < d->lns)
	{
		len = (int)ft_strlen(d->map[x++]);
		if (len > d->cols)
			d->cols = len;
	}
	if (!valid_first_walls(d) || !valid_remain_walls(d))
	{
		printf("Error!\nInvalid wall placement!\n");
		frees(d);
	}
	if (d->end_flag)
	{
		printf("Error\nCheck your input file!\n");
		frees(d);
		exit(1);
	}
	d->dmap = malloc(sizeof(char *) * d->lns);
	map_for_dda(d);
	fill_map_for_dda(d);
}

int	verify_conditions(t_data *d)
{
	while (d->x < (int)ft_strlen(d->map[d->y]))
	{
		if ((d->map[d->y][d->x] == '0' || d->map[d->y][d->x] == d->d)
			&& (d->map[d->y][d->x - 1] == ' ' || d->map[d->y][d->x + 1]
				== ' '))
			return (0);
		if ((d->map[d->y][d->x] == '0' || d->map[d->y][d->x] == d->d)
			&& ((d->map[d->y + 1][d->x] && d->map[d->y + 1][d->x] == ' ')
			|| (d->map[d->y - 1][d->x] && d->map[d->y - 1][d->x] == ' ')))
			return (0);
		if ((d->map[d->y][d->x] == '0' || d->map[d->y][d->x] == d->d)
			&& (!d->map[d->y + 1][d->x] || !d->map[d->y - 1][d->x]))
			return (0);
		if (d->map[d->y][d->x] && d->map[d->y][d->x] != '1'
			&& d->map[d->y][d->x] != d->d && d->map[d->y][d->x] != '0'
			&& d->map[d->y][d->x] != ' ')
			return (0);
		d->x++;
	}
	return (1);
}

void	fill_map_for_dda(t_data *d)
{
	int	x;
	int	y;
	int	len;

	x = 0;
	y = 0;
	while (y < d->lns)
	{
		len = (int)ft_strlen(d->map[y]);
		x = 0;
		while (x < len)
		{
			if (d->map[y][x] == ' ')
				d->dmap[y][x] = '1';
			x++;
		}
		y++;
	}
}
