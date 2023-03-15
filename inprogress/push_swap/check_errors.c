/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/15 18:20:12 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isbig(ssize_t num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	isnum(char **av)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (av[i])
	{
		if (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int	hasdup(char *av)
{
	int	i;

	i = 1;
	while (av[i + 1])
	{
		if(ft_atoi(&av[i]) == ft_atoi(&av[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_errors(char **av)
{
	int	i;

	if (isnum(av) == 0)
		return (1);
	i = 0;
	while (av[i])
	{
		if (isbig(ft_atoi(av[i]) == 1))
			return (1);
		if (hasdup(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
