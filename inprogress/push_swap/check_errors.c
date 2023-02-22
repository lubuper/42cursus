/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/22 15:17:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isbig(ssize_t num)
{
	if (num > 2147483647)
		return (1);
	return (0);
}

int	check_errors(int ac, char *av)
{
	int	i;
	int	j;
	int	temp_num;

	i = 1;
	while (av[i++])
	{
		j = i + 1;
		while (av[j])
			if (ft_atoi(&av[i]) == ft_atoi(&av[j++]))
				return (1);
	}
	while (i <= ac)
	{
		temp_num = ft_atoi(&av[i]);
		if (ft_isdigit(temp_num) == 0)
			return (1);
		else if (isbig(temp_num) == 1)
			return (1);
		i++;
	}
	ft_printf("OK");
	return (0);
}
