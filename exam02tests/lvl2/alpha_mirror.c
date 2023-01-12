/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:56:39 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/10 16:11:43 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	checker(char c)
{
	char	*basel;
	char	*baseu;
	int	i;
	int	j;

	i = 0;
	j = 25;
	baseu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	basel = "abcdefghijklmnopqrstuvwxyz";
	while (basel[i] || baseu[i])
	{
		if ((c == basel[i] || c == baseu[i]) && (c >= 'a' || c >= 'A') && (c <= 'm' ||c <= 'm'))
			return (j - i);
		else if (( c == basel[i] || c == baseu[i]) && (c >= 'n' || c >= 'N') && (c <= 'Z' || c <= 'z'))
			return (j - i);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	char	*basel;
	char	*baseu;
	int	b;

	basel = "abcdefghijklmnopqrstuvwxyz";
	baseu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				b = checker(av[1][i]);
				write (1, &basel[b], 1);
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				b = checker(av[1][i]);
				write (1, &baseu[b], 1);
			}

			else
				write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
