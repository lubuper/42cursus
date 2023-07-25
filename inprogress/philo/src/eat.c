/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:13:42 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/25 16:16:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_l_fork(t_phil *pointer)
{
	if (pthread_mutex_lock(&pointer->l_fork) == 0)
	{
		return (1);
	}
	return (0);
}

int	get_r_fork(t_phil *pointer)
{
	if (pthread_mutex_lock(pointer->r_fork) == 0)
		return (1);
	return (0);
}

void	put_down_forks(t_phil *pointer)
{
	pthread_mutex_unlock(&pointer->l_fork);
	pthread_mutex_unlock(pointer->r_fork);
}

void	lets_eat(t_phil *pointer)
{
	if (get_l_fork(pointer))
	{
		printmsg(FORKMSG, pointer);
		if (pointer->r_fork == 0)
		{
			ft_usleep(pointer->arg->t_until_death * 2);
			pthread_mutex_unlock(&pointer->l_fork);
			return ;
		}
		if (get_r_fork(pointer))
		{
			printmsg(FORKMSG, pointer);
			printmsg(EATMSG, pointer);
			pointer->last_meal = get_time();
			ft_usleep(pointer->arg->t_of_meal);
		}
	}
}
