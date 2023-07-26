/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:13:42 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/26 16:03:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_l_fork(t_phil *pointer)
{
	if (pthread_mutex_lock(&pointer->l_fork) == 0)
		return (1);
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
	if (pointer->arg->nb_phils > 1)
		pthread_mutex_unlock(pointer->r_fork);
}

void	lets_eat(t_phil *pointer)
{
	if (pointer->no % 2 == 1)
	{
		get_l_fork(pointer);
		printmsg(FORKMSG, pointer);
		if (pointer->arg->nb_phils > 1)
		{
			get_r_fork(pointer);
			printmsg(FORKMSG, pointer);
			printmsg(EATMSG, pointer);
			pointer->last_meal = get_time();
			ft_usleep(pointer->arg->t_of_meal);
		}
		else
			ft_usleep(pointer->arg->t_until_death * 2);
	}
	else
	{
		get_r_fork(pointer);
		printmsg(FORKMSG, pointer);
		get_l_fork(pointer);
		printmsg(FORKMSG, pointer);
		printmsg(EATMSG, pointer);
		pointer->last_meal = get_time();
		ft_usleep(pointer->arg->t_of_meal);
	}
}
