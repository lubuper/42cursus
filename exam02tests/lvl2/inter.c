/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:30:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/12 15:38:18 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	citer(char *str, char c, int p)
{
	int 	i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == p)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int	j;

		i = 0;
		j = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[2][j] == av[1][i] && citer(av[1], av[1][i], i)) 
				{
					write (1, &av[2][j], 1);
					j++;
					i++;
				}
				else if (av[2][j] == av[1][i] && !citer(av[1], av[1][i], 1))
				{
					j++;
					i++;
				}
				else
					j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
