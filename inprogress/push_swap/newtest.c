/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/16 15:32:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	hasdup(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] && av[i + 1])
	{
		while (av[i][j] == av[i + 1][j])
			j++;
		if (
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
		while (av[i])
		{
			if (hasdup(av[i]) == 1)
				printf("has dup");
			i++;
		}
	else
		printf("no args");
	return (0);
}
