/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/16 17:04:29 by lde-sous         ###   ########.fr       */
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

int	hasdup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i + 1])
	{
		j = i + 1;
		while (av[j])
		{
			if (avdiff(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_errors(char **av)
{
	int	i;

	if (isnum(av) == 0 || hasdup(av) == 1)
		return (1);
	i = 1;
	while (av[i])
	{
		if (isbig(spatoi(av[i])) == 1)
			return (1);
		i++;
	}
	return (0);
}
