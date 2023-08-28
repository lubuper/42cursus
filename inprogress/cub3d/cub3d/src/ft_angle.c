/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 14:29:59 by alex              #+#    #+#             */
/*   Updated: 2023/08/28 12:59:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_angle(int nbr)
{
	if (nbr == 0)
		return (0);
	return (nbr * WIDTH / 60);
}

void	dir_angle(t_data *d)
{
	if (d->d == 'E')
		d->angle = ft_angle(0);
	else if (d->d == 'N')
		d->angle = ft_angle(90);
	else if (d->d == 'W')
		d->angle = ft_angle(180);
	else if (d->d == 'S')
		d->angle = ft_angle(270);
}
