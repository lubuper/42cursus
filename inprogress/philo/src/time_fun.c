/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:08:31 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/24 20:53:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	get_time(void)
{
	struct timeval	ftime;
	long int		time;

	time = 0;
	if (gettimeofday(&ftime, NULL))
		return (-1);
	time = (ftime.tv_sec * 1000) + (ftime.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int miliseconds)
{
	long int	start;

	start = 0;
	start = get_time();
	while (get_time() - start < miliseconds)
		usleep(miliseconds / 10);
}
