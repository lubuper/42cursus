/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/26 17:02:57 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	printmsg(char *str, t_data *p)
{
	sem_wait(&p->arg.write_sem);
	if (p->arg.is_dead == 0)
		print_changes(str, p);
	sem_post(&p->arg.write_sem);
}

void	job(t_data *p)
{
	int		m;

	m = 0;
	if (p->ph->no % 2 == 1)
		ft_usleep(10);
	while (1)
	{
		if (p->arg.is_dead)
			return ;
		lets_eat(p);
		put_down_forks(p);
		m++;
		if (p->arg.meals == m)
		{
			printmsg(ENDMSG, p);
			return ;
		}
		printmsg(SLEEPMSG, p);
		ft_usleep(p->arg.t_sleep);
		printmsg(THINKMSG, p);
	}
}

void	processes_start(t_data *p)
{
	int		i;

	i = 0;
	while (i < p->arg.nb_phils)
	{
		p->ph[i].pid = fork();
		i++;
	}
	if (p->ph[i].pid == 0)
	{
		job(p);
	}
	i = 0;
	//pthread_create(&p->arg.death, NULL, check_death, p);
	//thread_detach(p->arg.death);
	/* while (i < p->arg.nb_phils)
	{
		pthread_join(p->ph[i].thread_no, NULL);
		i++;
	}
	return ; */
}

int	main(int ac, char **av)
{
	t_data	p;

	if (valid_args(ac, av, &p) == 1)
		return (0);
	if (p.arg.meals == 0)
		return (0);
	processes_start(&p);
	free_vars(&p);
	return (0);
}
