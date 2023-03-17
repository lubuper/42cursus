/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:52:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/17 13:42:26 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	maxdigits(t_stack *stack)
{
	int	n;
	int	max_e;

	max_e = stack->content;
	n = 0;
	while (stack->next)
	{
		if (max_e < stack->content)
			max_e = stack->content;
		stack = stack->next;
	}
	while (max_e)
	{
		max_e /= 10;
		n++;
	}
	return (n);
}

orderlsb
