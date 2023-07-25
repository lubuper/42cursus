/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/25 16:18:43 by lde-sous         ###   ########.fr       */
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
		if ((get_time() - dp->ph[i].last_meal)
			>= (long int)dp->arg.t_until_death)
		{
			pthread_mutex_unlock(&dp->arg.last_mutex);
			printmsg(DEADMSG, &dp->ph[i]);
			pthread_mutex_lock(&dp->arg.end_mutex);
			dp->arg.is_dead = 1;
			pthread_mutex_unlock(&dp->arg.end_mutex);
			return (NULL);
		}
		else
			pthread_mutex_unlock(&dp->arg.last_mutex);
		i++;
	}
	return (NULL);
}

void	free_vars(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->arg.nb_phils)
	{
		pthread_mutex_destroy(&p->ph[i++].l_fork);
	}
	pthread_mutex_destroy(&p->arg.write_mutex);
	free(p->ph);
}
