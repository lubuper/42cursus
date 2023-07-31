/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:40:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/31 20:59:51 by lde-sous         ###   ########.fr       */
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
		/* sem_wait(&p->arg.write_sem);
		printf("PHILOSOPHER %d\n", p->ph->no);
		sem_post(&p->arg.write_sem);
		sem_wait(&p->arg.write_sem);
		printf("TIME OF DEATH = %ld\n", (long int)p->arg.t_until_death);
		sem_post(&p->arg.write_sem);
		sem_wait(&p->arg.write_sem);
		printf("TIME OF MEAL = %d\n", p->arg.t_of_meal);
		sem_post(&p->arg.write_sem);
		sem_wait(&p->arg.write_sem);
		printf("TIME OF LAST MEAL= %ld\n", p->ph->last_meal);
		sem_post(&p->arg.write_sem);
		sem_wait(&p->arg.write_sem);
		printf("GETIME = %ld\n", get_time());
		sem_post(&p->arg.write_sem);
		sem_wait(&p->arg.write_sem);
		printf("TIME - TIME OF LAST MEAL= %ld\n", get_time() - p->ph[p->ph->no].last_meal);
		sem_post(&p->arg.write_sem); */
		sem_wait(&p->arg.final_sem);
		if ((get_time() - p->ph->last_meal)
			>= (long int)p->arg.t_until_death)
		{
			sem_post(&p->arg.final_sem);
			printmsg(DEADMSG, p);
			sem_wait(&p->arg.final_sem);
			p->arg.is_dead = 1;
			sem_post(&p->arg.final_sem);
			return (NULL);
		}
		else
			sem_post(&p->arg.final_sem);
	}
	return (NULL);
}

void	free_vars(t_data *p)
{
	int	i;

	i = 0;
	
	while (i < p->arg.nb_phils)
	{
		kill(p->ph[i].pid, 15);
		i++;
	}
	sem_destroy(&p->arg.final_sem);
	sem_destroy(&p->arg.forks);
	sem_destroy(&p->arg.write_sem);
	free(p->ph);
}
