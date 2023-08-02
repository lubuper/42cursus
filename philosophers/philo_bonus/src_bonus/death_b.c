/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/02 18:16:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	*check_death(void *data)
{
	t_data	*p;

	p = (t_data *)data;
	ft_usleep(p->arg.t_until_death);
	while (1)
	{
		if (p->arg.is_dead == 1)
			return (NULL);
		sem_wait(p->arg.verif);
		if ((get_time() - p->ph.last_meal)
			>= (long int)p->arg.t_until_death)
		{
			if (p->arg.finished_meals == 0)
			{
				printmsg(DEADMSG, p);
				p->arg.is_dead = 1;
				sem_wait(p->arg.write_sem);
			}
			sem_post(p->arg.verif);
			exit(0);
		}
		else
			sem_post(p->arg.verif);
	}
	return (NULL);
}

void	free_vars(t_data *p)
{
	int	i;

	i = 0;
	while (i < p->arg.nb_phils)
	{
		kill(p->arg.pid[i], 9);
		i++;
	}
	free(p->arg.pid);
	sem_close(p->arg.forks);
	sem_close(p->arg.write_sem);
	sem_close(p->arg.verif);
	sem_unlink("write_sem");
	sem_unlink("verif");
	sem_unlink("death");
	sem_unlink("forks");
}
