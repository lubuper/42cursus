/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/11 12:31:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*job(void *voidling)
{
	int		m;
	char *str;
	
	m = 0;
	str = "is eating\n";
	t_phil *pointer = (t_phil *)voidling;
	while (1)
	{
		pthread_mutex_lock(&pointer->arg.write_mutex);
		print_changes(str, pointer);
		pthread_mutex_unlock(&pointer->arg.write_mutex);
		ft_usleep(pointer->arg.t_of_meal);
		//printf("sleeping time");
		m++;
		if (pointer->arg.meals == m)
		return (0);
	}
}

void	thread_maker(t_phil *p)
{
	int		i;

	i = 1;
	while (i <= p->arg.nb_phils)
	{
		pthread_create(&p->thread_no, NULL, job, p);
		i++;		
	}
	i = 1;
	while (i <= p->arg.nb_phils)
	{
		pthread_join(p->thread_no, NULL);
		i++;		
	}
	return ;
}

int	main(int ac, char **av)
{
	t_phil	p;

	if (valid_args(ac, av, &p) == 1)
		return (0);
	//init_vars(ac, av, &p);
	thread_maker(&p);
	free_vars(&p);
	return (0);
}
