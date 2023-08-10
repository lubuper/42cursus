/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:30:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/10 15:37:25 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_map(int keycode, t_data *d)
{
	if (keycode == ESC || keycode == M_CLICK_X)
		frees(d);
	return (0);
}
void	frees(t_data *d)
{
	int	i;

	i = 0;
	if (d->map)
	{
		while (i < d->lines)
		{
			free(d->map[i]);
			free(d->mapdup[i++]);
		}
		free(d->map);
		free(d->mapdup);
	}
	exit(0);
}