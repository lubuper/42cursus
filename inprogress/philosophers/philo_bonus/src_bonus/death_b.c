/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/26 17:05:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	check_death(t_data *p)
{
	int		i;

	i = 0;
	ft_usleep(p->arg.t_until_death);
	while (i < p->arg.nb_phils)
	{
		sem_wait(&p->arg.final_sem);
		if ((get_time() - p->ph[i].last_meal)
			>= (long int)p->arg.t_until_death)
		{
			sem_post(&p->arg.final_sem);
			printmsg(DEADMSG, p);
			sem_wait(&p->arg.final_sem);
			p->arg.is_dead = 1;
			sem_post(&p->arg.final_sem);
			return ;
		}
		else
			sem_post(&p->arg.final_sem);
		i++;
	}
	return ;
}

void	free_vars(t_data *p)
{
	int	i;

	i = 0;
	sem_destroy(&p->arg.final_sem);
	sem_destroy(&p->arg.forks);
	sem_destroy(&p->arg.write_sem);
	free(p->ph);
}
