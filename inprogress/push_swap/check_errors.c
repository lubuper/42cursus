/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/03 20:47:05 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isbig(ssize_t num)
{
	if (num > 2147483647)
		return (1);
	ft_printf("ola\n");
	return (0);
}

int	check_errors(int ac, char **av)
{
	int	i;
	int	j;
	int	temp_num;
	char	**ptr;

	i = -1;
	ac--;
	ptr = av;
	while (av && ++i < ac) 
	{
		j = i + 1;
		while (j <= ac)
		{
			if (av[0] == av[j++])
				return (1);
		}
		av++;
	}
	i = 0;
	av = ptr;
	while (i < ac)
	{
		temp_num = ft_atoi(av[i]);
		ft_printf("%d\n", temp_num);
/*		if (ft_isdigit(temp_num) == 0)
		{
			ft_printf("khsajdh");
			return (1);
		}*/
		if (isbig(temp_num) == 1)
			return (1);
		i++;
	}
	return (0);
}
