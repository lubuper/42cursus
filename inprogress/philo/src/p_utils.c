/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/10 20:55:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ph_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	if (str[i] == '+')
			i++;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (result);
}

void	init_vars(int ac, char **av, t_phil *p)
{
	p->arg.nb_phils = ph_atoi(av[1]);
	printf("nb phils %d\n", p->arg.nb_phils);
	p->arg.t_until_death = ph_atoi(av[2]);
	printf("time to die %d\n", p->arg.t_until_death);
	p->arg.t_during_meal = ph_atoi(av[3]);
	printf("time to eat %d\n", p->arg.t_during_meal);
	p->arg.t_ofsleep = ph_atoi(av[4]);
	printf("time to sleep %d\n", p->arg.t_ofsleep);
	pthread_mutex_init(&p->arg.mutex, NULL);
	if (ac == 6)
		p->arg.meals = ph_atoi(av[5]);
	else if (ac == 5)
		p->arg.meals = -1;
	//p->ph->no = 0;
	printf("\n");
}

void	free_vars(t_phil *p)
{
	pthread_mutex_destroy(&p->arg.mutex);
}

int	valid_args(int ac, char **av)
{
	int	n;
	n = 1;
		if (ac < 5 || ac > 6)
	{
		printf("Think about how many parameters you need\n");		
		return (1);
	}
	while (n <= ac)
	{
		if (ph_atoi(av[n]) < 0)
		{
			printf("the atoi of n = %d\n", ph_atoi(av[n]));
			return (1);
		}
		n++;
	}
	printf("everything valid!\n");
	return (0);	
}
