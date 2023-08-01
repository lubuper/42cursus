/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:13:42 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/01 16:42:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	put_down_forks(t_data *p)
{
	sem_post(p->arg.forks);
	if (p->arg.nb_phils > 1)
		sem_post(p->arg.forks);
}

void	lets_eat(t_data *p)
{
	sem_wait(p->arg.forks);
	printmsg(FORKMSG, p);
	if (p->arg.nb_phils > 1)
	{
		sem_wait(p->arg.forks);
		printmsg(FORKMSG, p);
		printmsg(EATMSG, p);
		p->ph.last_meal = get_time();
		ft_usleep(p->arg.t_of_meal);
	}
	else
		ft_usleep(p->arg.t_until_death * 2);
}
