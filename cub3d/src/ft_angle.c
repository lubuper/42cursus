/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:29:59 by alex              #+#    #+#             */
/*   Updated: 2023/09/20 12:43:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
