/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/14 18:38:34 by lde-sous         ###   ########.fr       */
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

void	free_vars(t_data *p)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&p->arg.write_mutex);
	while (i < p->arg.nb_phils)
	{
		pthread_mutex_destroy(&p->ph[i++].l_fork);
	}
	free(p->ph);
}

void	philo_args(t_data *p)
{
	int		i;

	i = 0;
	p->ph = malloc(sizeof(t_phil) * p->arg.nb_phils);
	while (i < p->arg.nb_phils)
	{
		p->ph[i].no = i + 1;
		p->ph[i].last_meal = get_time() - p->arg.t_start;
		p->ph[i].r_fork = NULL;
		p->ph[i].arg = &p->arg;
		pthread_mutex_init(&p->ph[i].l_fork, NULL);
		if (p->arg.nb_phils == 1)
			break ;
		if (i + 1 == p->arg.nb_phils)
			p->ph[i].r_fork =  &p->ph[0].l_fork;
		else
			p->ph[i].r_fork =  &p->ph[i + 1].l_fork;
		i++;
	}
}

void	get_args(int ac, char **av, t_data *p)
{
	p->arg.nb_phils = ph_atoi(av[1]);
	p->arg.t_until_death = ph_atoi(av[2]);
	p->arg.t_of_meal = ph_atoi(av[3]);
	p->arg.t_sleep = ph_atoi(av[4]);
	pthread_mutex_init(&p->arg.write_mutex, NULL);
	if (ac == 6)
		p->arg.meals = ph_atoi(av[5]);
	else if (ac == 5)
		p->arg.meals = -1;
	p->arg.t_start = get_time();
	philo_args(p);
}

int	valid_args(int ac, char **av, t_data *p)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9' || j > 10)
			{
				printf("Think in numbers you can count\n");
				return (1);
			}
			j++;	
		}
		i++;
	}
	if (ac < 5 || ac > 6)
	{
		printf("Think about how many parameters you need\n");		
		return (1);
	}
	get_args(ac, av, p);
	printf("everything valid!\n");
	return (0);	
}

void	print_changes(char *str, t_phil *p)
{
	long int	time_now;
	
	time_now = get_time() - p->arg->t_start;
	printf("%ld ", time_now);
	printf("%d %s", p->no, str);
}