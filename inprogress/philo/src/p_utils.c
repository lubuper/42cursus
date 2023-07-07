/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/07 11:16:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	positive_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (-1);
	if (str[i] == '+')
			i++;
	while (str[i])
	{
		if (str[i] >= 48) || (str[i] <= 57)
			result = result * 10 + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (result);
}

void	init_vars(int ac, char **av, t_phil)
{
	t_phil->t_args.philos = positive_atoi(av[1]);
	t_phil->t_args.ttdie = positive_atoi(av[2]);
	t_phil->t_args.tteat = positive_atoi(av[3]);
	t_phil->t_args.ttsleep = positive_atoi(av[4]);
	if (av[5])
		t_phil->t_args.meals_num = positive_atoi(av[5]);
	else
		t_phil->t_args.meals_num = -1;
	
}

int	valid_args(int ac, char **av)
{
	int	n;

	n = 0;
	if (ac != 5 && ac != 6)
		return (0);
	while (n <= ac)
		if (positive_atoi(av[n]) < 0)
			return (0);
	return (1);	
}
