/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:32:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/15 15:28:23 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isdup(char **str)
{
	
}

int	check_errors(char **str)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (str[i][j])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (1);
			else if (isdup(str[i][j] == 1)
				return (1);
			else if ()
				return (1);
				j++;
		}
		i++;
	}
	return (0);
}
