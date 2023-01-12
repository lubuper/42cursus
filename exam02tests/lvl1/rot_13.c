/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:38:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/10 11:50:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if ((av[1][i] >= 'n' && av[1][i] <= 'z') || 
					(av[1][i] >= 'N' && av[1][i] <= 'Z'))
				av[1][i] = av[1][i] - 13;
			else if ((av[1][i] >= 64 && av[1][i] <= 77) ||
					(av[1][i] >= 97 && av[1][i] <= 109))
				av[1][i] = av[1][i] + 13;
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
