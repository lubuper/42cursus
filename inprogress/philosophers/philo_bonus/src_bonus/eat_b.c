/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:13:42 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/31 17:03:06 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

int	get_l_fork(t_data *p)
{
	if (sem_wait(&p->arg.forks))
		return (1);
	return (0);
}

int	get_r_fork(t_data *p)
{
	if (sem_wait(&p->arg.forks))
		return (1);
	return (0);
}

void	put_down_forks(t_data *p)
{
	sem_post(&p->arg.forks);
	if (p->arg.nb_phils > 1)
		sem_post(&p->arg.forks);
}

void	lets_eat(t_data *p)
{
		get_l_fork(p);
		printmsg(FORKMSG, p);
		if (p->arg.nb_phils > 1)
		{
			get_r_fork(p);
			printmsg(FORKMSG, p);
			printmsg(EATMSG, p);
			p->ph->last_meal = get_time();
			ft_usleep(p->arg.t_of_meal);
		}
		else
			ft_usleep(p->arg.t_until_death * 2);
}
