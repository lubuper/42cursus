/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/20 08:53:27 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*check_death(void *ph)
{
	t_phil	*p;

	p = (t_phil *)ph;
	ft_usleep(p->arg->t_until_death);
	pthread_mutex_lock(&p->arg->last_mutex);
	//pthread_mutex_lock(&p->arg->end_mutex);
	printf("time meal = %ld\n", get_time() - p->last_meal);
	printf("time to die = %d\n", p->arg->t_until_death);
	if ((get_time() - p->last_meal) >= (long)p->arg->t_until_death)
	{
		pthread_mutex_unlock(&p->arg->last_mutex);
		//pthread_mutex_unlock(&p->arg->end_mutex);
		printmsg(DEADMSG, p);
		p->arg->is_dead = 1;
		return (NULL);
	}
	pthread_mutex_unlock(&p->arg->last_mutex);
	//pthread_mutex_unlock(&p->arg->end_mutex);
	return (NULL);
}

void	is_dead(t_phil *ph)
{
	if (ph->arg->is_dead == 1)
	{
		return ;
	}
}