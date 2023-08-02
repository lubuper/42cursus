/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/02 18:17:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

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

void	get_args(int ac, char **av, t_data *p)
{
	p->arg.nb_phils = ph_atoi(av[1]);
	p->arg.t_until_death = ph_atoi(av[2]);
	p->arg.t_of_meal = ph_atoi(av[3]);
	p->arg.t_sleep = ph_atoi(av[4]);
	p->arg.is_dead = 0;
	sem_unlink("write_sem");
	sem_unlink("verif");
	sem_unlink("death");
	sem_unlink("forks");
	p->arg.verif = sem_open("verif", O_CREAT, 0644, 1);
	p->arg.write_sem = sem_open("write_sem", O_CREAT, 0644, 1);
	p->arg.forks = sem_open("forks", O_CREAT, 0644, p->arg.nb_phils);
	p->arg.pid = malloc(sizeof(int) * p->arg.nb_phils);
	if (ac == 6)
		p->arg.meals = ph_atoi(av[5]);
	else if (ac == 5)
		p->arg.meals = -1;
	p->arg.t_start = get_time();
	p->arg.finished_meals = 0;
	p->ph.last_meal = 1;
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
	return (0);
}

void	print_changes(char *str, t_data *p)
{
	long int	time_now;

	time_now = get_time() - p->arg.t_start;
	printf("%ld ", time_now);
	printf("%d %s", p->ph.no, str);
}
