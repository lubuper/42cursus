/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/10 20:55:39 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*job(void *voidling)
{
	int		m;
	m = 0;
	t_phil *pointer = (t_phil *)voidling;
	while (1)
	{
		//printf("philo %d\n", pointer->ph->no);
		pthread_mutex_lock(&pointer->arg.mutex);
		printf("pointer time to eat = %d\n", pointer->arg.t_during_meal);
		ft_usleep(pointer->arg.t_during_meal);
		pthread_mutex_unlock(&pointer->arg.mutex);
		//printf("sleeping time");
		m++;
		if (pointer->arg.meals == m)
		return (0);
	}
}

void	thread_maker(t_phil *p)
{
	int		i;
	pthread_t	*thread;

	thread = malloc(sizeof(t_phil) * (p->arg.nb_phils));
	i = 1;
	while (i <= p->arg.nb_phils)
	{
		pthread_create(&thread[i], NULL, job, p);
		i++;		
	}
	i = 1;
	while (i <= p->arg.nb_phils)
	{
		pthread_join(thread[i], NULL);
		i++;		
	}
	return ;
}

int	main(int ac, char **av)
{
	t_phil	p;

	if (valid_args(ac, av) == 1)
		return (0);
	init_vars(ac, av, &p);
	thread_maker(&p);
	free_vars(&p);
	return (0);
}
