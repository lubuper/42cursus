/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:14 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/10 17:11:36 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	first;
	int	second;
	int	third;
	int	result;

	if (ac == 4)
	{
		result = 0;
		first = atoi(av[1]);
		second = av[2][0];
		third = atoi(av[3]);
		if (second == '+')
			result = first + third;
		else if (second == '-')
			result = first - third;
		else if (second == '*')
			result = first * third;
		else if (second == '/')
			result = first / third;
		else if (second == '%')
			result = first % third;
		printf("%d\n", result);
	}
	else
		write (1, "\n", 1);
	return (0);
}
