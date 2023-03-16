/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:50:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/16 15:50:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	spatoi(const char *nptr)
{
	int		sign;
	int		i;
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
	return (result * sign);
}

int	avdiff(char *av1, char *av2)
{
	int	i;

	i = 0;
	while (av1[i] && av2[i] && av1[i] == av2[i])
		i++;
	return ((unsigned char)av1[i] - (unsigned char)av2[i]);
}
