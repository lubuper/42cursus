/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:36:33 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/15 18:53:47 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*int	isnum(char **av)
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
*/

int	isbig(ssize_t num)
{
	if (num > 2147483647 || num < -2147483648)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		printf("%d\n", isbig(atoi(*av)));
	else
		printf("no args");
	return (0);
}
