/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:51:41 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 14:07:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	look(t_data *d)
{
	if (d->kflag.look_l == 1)
	{
		d->pa -= DR;
		if (d->pa <= 0)
			d->pa += 2 * PI;
	}
	if (d->kflag.look_r == 1)
	{
		d->pa += DR;
		if (d->pa > 2 * PI)
			d->pa -= 2 * PI;
	}
}