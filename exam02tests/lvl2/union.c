/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:53:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/12 22:46:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	citer(char *str, char c, int p)
{
	int	i;

	i = 0;
	while (str[i] && i < p)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
		return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (citer(av[1], av[1][i], i))
				write (1, &av[1][i], 1);
			i++;
		}
		while (av[2][o])
		{
			if (citer(av[2], av[2][o], o) && (citer(av[1], av[2][o], i)))
				write (1, &av[2][o], 1);
			o++;
		}
	}
	write (1, "\n", 1);
}
