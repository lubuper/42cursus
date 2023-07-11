/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/11 12:32:25 by lde-sous         ###   ########.fr       */
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

//void	init_vars(int ac, char **av, t_phil *p)
//{
//	
//}

void	free_vars(t_phil *p)
{
	pthread_mutex_destroy(&p->arg.write_mutex);
}

void	get_args(int ac, char **av, t_phil *p)
{
	p->arg.nb_phils = ph_atoi(av[1]);
	printf("nb phils %d\n", p->arg.nb_phils);
	p->arg.t_until_death = ph_atoi(av[2]);
	printf("time to die %d\n", p->arg.t_until_death);
	p->arg.t_of_meal = ph_atoi(av[3]);
	printf("time to eat %d\n", p->arg.t_of_meal);
	p->arg.t_sleep = ph_atoi(av[4]);
	printf("time to sleep %d\n", p->arg.t_sleep);
	pthread_mutex_init(&p->arg.write_mutex, NULL);
	if (ac == 6)
		p->arg.meals = ph_atoi(av[5]);
	else if (ac == 5)
		p->arg.meals = -1;
	p->arg.t_start = get_time();
}

int	valid_args(int ac, char **av, t_phil *p)
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
	
	time_now = get_time() - p->arg.t_start;
	printf("%ld ms ", time_now);
	printf("%s", str);
	//printf("Philo %d %s", p->ph->no, str);
}