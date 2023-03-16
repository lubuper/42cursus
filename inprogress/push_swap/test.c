/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:36:33 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/16 15:24:56 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	isbig(ssize_t num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	spatoi(const char *nptr)
{
	int	sign;
	int	i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (result > 2147483647 || result < -2147483648)
		printf("Arg too big");
	return (result * sign);
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

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
		while (av[i])
		{
			if (isnum(av) == 0)
				printf("It has not only numbers");
			if (isbig(spatoi(av[i])) == 1)
				printf("BIG");
			i++;
		}
	else
		printf("no args");
	return (0);
}
