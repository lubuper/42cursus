/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/13 20:50:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	printmsg(char *str, t_phil *pointer)
{
	pthread_mutex_lock(&pointer->arg->write_mutex);
	print_changes(str, pointer);
	pthread_mutex_unlock(&pointer->arg->write_mutex);
}

int	get_l_fork(t_phil *pointer)
{
	if (pthread_mutex_lock(&pointer->l_fork) == 0)
	{
		return (1);
	}
	return (0);
}

void	put_down_forks(t_phil *pointer)
{
	pthread_mutex_unlock(&pointer->l_fork);
}

void	*job(void *voidling)
{
	int		m;
	t_phil *pointer;
	
	m = 0;
	pointer = (t_phil *)voidling;
	if (pointer->arg->meals == 0)
		return (0);
	while (1)
	{
		if (get_l_fork(pointer))
		{
			printmsg(EATMSG, pointer);
			ft_usleep(pointer->arg->t_of_meal);
		}
		put_down_forks(pointer);
		printmsg(SLEEPMSG, pointer);
		ft_usleep(pointer->arg->t_sleep);
		printmsg(THINKMSG, pointer);
		ft_usleep(10);

		m++;
		if (pointer->arg->meals == m)
			return (0);
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
	//init_vars(ac, av, &p);
	thread_maker(&p);
	free_vars(&p);
	return (0);
}
