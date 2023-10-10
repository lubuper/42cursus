/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:30:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/03 18:52:39 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	keyrelease(int keycode, t_data *d)
{
	if (keycode == W)
		d->kflag.forward = 0;
	else if (keycode == A)
		d->kflag.strafe_l = 0;
	else if (keycode == S)
		d->kflag.backwards = 0;
	else if (keycode == D)
		d->kflag.strafe_r = 0;
	else if (keycode == LEFT_A)
		d->kflag.look_l = 0;
	else if (keycode == RIGHT_A)
		d->kflag.look_r = 0;
	return (0);
}

int	keypress(int keycode, t_data *d)
{
	if (keycode == ESC || keycode == M_CLICK_X)
		frees(d);
	else if (keycode == ENTER)
		printf("Enter pressed - refreshing!\n");
	else if (keycode == W)
		d->kflag.forward = 1;
	else if (keycode == A)
		d->kflag.strafe_l = 1;
	else if (keycode == S)
		d->kflag.backwards = 1;
	else if (keycode == D)
		d->kflag.strafe_r = 1;
	else if (keycode == LEFT_A)
		d->kflag.look_l = 1;
	else if (keycode == RIGHT_A)
		d->kflag.look_r = 1;
	return (0);
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

void	*onelloc(size_t nmemb, size_t size)
{
	char		*tempvector;
	size_t		i;
	size_t		total;

	total = nmemb * size;
	tempvector = malloc(total + 1);
	if (!tempvector)
		return (NULL);
	i = 0;
	while (i < total)
	{
		tempvector[i] = '1';
		i++;
	}
	tempvector[i] = 0;
	return ((void *)tempvector);
}

void	handle_file_aux(t_data *d)
{
	if (d->lns < 3)
	{
		printf("Error\nInvalid map!\n");
		frees(d);
	}
}
