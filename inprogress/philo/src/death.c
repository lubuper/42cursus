/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/24 18:45:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*check_death(void *data)
{
	t_data	*dp;
	int		i;

	i = 0;
	dp = (t_data *)data;
	ft_usleep(dp->arg.t_until_death);
	while (i < dp->arg.nb_phils)
	{
		pthread_mutex_lock(&dp->arg.last_mutex);
		if ((get_time() - dp->ph[i].last_meal) >= (long int)dp->arg.t_until_death)
		{
			printmsg(DEADMSG, &dp->ph[i]);
			pthread_mutex_lock(&dp->arg.end_mutex);
			dp->arg.is_dead = 1;
			pthread_mutex_unlock(&dp->arg.end_mutex);
			pthread_mutex_unlock(&dp->arg.last_mutex);
			return (NULL);
		}
		else
			pthread_mutex_unlock(&dp->arg.last_mutex);
		i++;
	}
	return (NULL);
}
