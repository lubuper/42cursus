/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/25 16:16:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	printmsg(char *str, t_phil *pointer)
{
	pthread_mutex_lock(&pointer->arg->write_mutex);
	if (pointer->arg->is_dead == 0)
		print_changes(str, pointer);
	pthread_mutex_unlock(&pointer->arg->write_mutex);
}

void	*job(void *voidling)
{
	int		m;
	t_phil	*pointer;

	m = 0;
	pointer = (t_phil *)voidling;
	if (pointer->no % 2 == 1)
		ft_usleep(10);
	while (1)
	{
		if (pointer->arg->is_dead)
			return (NULL);
		lets_eat(pointer);
		put_down_forks(pointer);
		m++;
		if (pointer->arg->meals == m)
		{
			printmsg(ENDMSG, pointer);
			return (NULL);
		}
		printmsg(SLEEPMSG, pointer);
		ft_usleep(pointer->arg->t_sleep);
		printmsg(THINKMSG, pointer);
	}
}

void	thread_maker(t_data *p)
{
	int		i;

	i = 0;
	while (i < p->arg.nb_phils)
	{
		pthread_create(&p->ph[i].thread_no, NULL, job, &p->ph[i]);
		i++;
	}
	i = 0;
	pthread_create(&p->arg.death, NULL, check_death, p);
	pthread_detach(p->arg.death);
	while (i < p->arg.nb_phils)
	{
		pthread_join(p->ph[i].thread_no, NULL);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	p;

	if (valid_args(ac, av, &p) == 1)
		return (0);
	if (p.arg.meals == 0)
		return (0);
	thread_maker(&p);
	free_vars(&p);
	return (0);
}
