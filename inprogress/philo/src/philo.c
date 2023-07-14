/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/14 19:06:15 by lde-sous         ###   ########.fr       */
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

int	get_r_fork(t_phil *pointer)
{
	if (pthread_mutex_lock(pointer->r_fork) == 0)
		return (1);
	return (0);
}

void	put_down_forks(t_phil *pointer)
{
	pthread_mutex_unlock(&pointer->l_fork);
	pthread_mutex_unlock(pointer->r_fork);
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
		if (pointer->arg->nb_phils % 2 == 1)
		{
			if(pointer->no % 2 == 1)
				ft_usleep(10);
		}
		if (get_l_fork(pointer))
		{
			printmsg(FORKMSG, pointer);
			if (pointer->arg->nb_phils == 1)
			{
				pthread_mutex_unlock(&pointer->l_fork);
				return (NULL);
			}
			while (&get_r_fork == 0)
				ft_usleep(1);
			if (get_r_fork(pointer))
			{
				printmsg(FORKMSG, pointer);
				printmsg(EATMSG, pointer);
				/* pointer->last_meal = get_time() - pointer->last_meal;
				pthread_mutex_lock(&pointer->arg->write_mutex);
				printf("last meal = %ld\n", pointer->last_meal);
				pthread_mutex_unlock(&pointer->arg->write_mutex);*/
				ft_usleep(pointer->arg->t_of_meal);
			}
		}
		put_down_forks(pointer);
		m++;
		if (pointer->arg->meals == m)
		{
			printmsg(ENDMSG, pointer);
			return (0);
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
