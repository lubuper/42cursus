/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:30:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 20:02:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_map(int keycode, t_data *d)
{
	if (keycode == ESC || keycode == M_CLICK_X)
		frees(d);
	else if (keycode == W)
	{
		printf("Moving forward!\n");
		d->py -= 0.1;
		if (d->map[(int)d->py][(int)d->px] == '1' || d->map[(int)d->py][(int)d->px] == ' ')
			d->py += 0.1;
	}
	else if (keycode == A)
	{
		printf("Strafing left!\n");
		d->px -= 0.1;
		if (d->map[(int)d->py][(int)d->px] == '1' || d->map[(int)d->py][(int)d->px] == ' ')
			d->px += 0.1;
	}
	else if (keycode == S)
	{
		printf("Moving backwards!\n");
		d->py += 1.0;
		if (d->map[(int)d->py][(int)d->px] == '1' || d->map[(int)d->py][(int)d->px] == ' ')
			d->py -= 1.0;
		else
		{
			d->py -= 1.0;
			d->py += 0.1 ; 
		}
	}
	else if (keycode == D)
	{
		printf("Strafing right!\n");
		d->px += 1.0;
		if (d->map[(int)d->py][(int)d->px] == '1' || d->map[(int)d->py][(int)d->px] == ' ')
			d->px -= 1.0;
		else
		{
			d->px -= 1.0;
			d->px += 0.1; 
		}
	}
	else if (keycode == ENTER)
	{
		printf("Enter pressed - refreshing!\n");
	}
	return (0);
}

int	close_win(t_data *d)
{
	frees(d);
	return (0);
}

void	frees(t_data *d)
{
	int	i;

	i = 0;
	if (d->flag_six == 6)
	{
		while (i < d->lines && d->lines > 0)
		{
			if (d->map[i])
				free(d->map[i]);
			i++;
		}
	}
	free(d->map);
	free_imgs(d);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
}

void	free_imgs(t_data *d)
{
	if (d->i.floor_c)
		free(d->i.floor_c);
	if (d->i.ceil_c)
		free(d->i.ceil_c);
	if (d->i.nwall)
		free(d->i.nwall);
	if (d->i.wwall)
		free(d->i.wwall);
	if (d->i.ewall)
		free(d->i.ewall);
	if (d->i.swall)
		free(d->i.swall);
}

char	*ft_specialdup(char *str)
{
	char	*sdup;
	int		i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	sdup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1 - i));
	if (!sdup)
		return (NULL);
	while (str[i])
	{
		sdup[i] = str[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}

/* void	pixel_to_scr(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->i.addr + (y * d->i.line_len + x * (d->i.bitspp / 8));
	*(unsigned int *) dst = color;
} */
