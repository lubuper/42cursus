/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:57:39 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/29 19:58:27 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element;

	element = *stack_a;
	while (element->next != 0)
	{
		if (element->content > element->next->content || (*stack_b))
			return (0);
		element = element->next;
	}
	return (1);
}

t_stack	**transformstack(t_stack **stack_a)
{
	t_stack	**final_stack;

	final_stack = malloc(sizeof(stack_a));
	if (!final_stack)
	{
		free(stack_a);
		return (NULL);
	}
	final_stack = 0;
	return (final_stack);
}

int	maxbits(t_stack **stack)
{
	t_stack	*element;
	int		maxb;
	int		bigg;

	element = *stack;
	maxb = 0;
	bigg = element->content;
	while (element->next)
	{
		if (bigg < element->content)
			bigg = element->content;
		element = element->next;
	}
	while ((bigg >> maxb) != 0)
		maxb++;
	return (maxb);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	mbits;

	i = 0;
	size = stsize(*stack_a);
	mbits = maxbits(stack_a);
	while (i < mbits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->content >> i) & 1) == 1)
				rotate_a(stack_a);
			else
				push_b(stack_b, stack_a);
			j++;
		}
		while (stsize(*stack_b) != 0)
			push_a(stack_a, stack_b);
		i++;
	}
}
