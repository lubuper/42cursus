/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:52:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/21 14:52:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	
}
*/
int	maxbits(t_stack **stack)
{
	t_list	element;
	int		maxb;
	int		bigg;
	
	element = *stack;
	maxb = 0;
	bigg = element->content;
	while (element)
	{
		if (bigg < element->content)
			bigg = element->content;
		element = element->next;
	}
	while ((bigg >> maxb) != 0)
		maxb++;
	return (maxb);
}

void	is_sorted(t_stack **stack_a, t_stack, **stack_b)
{
	while ((*stack_a)->next)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			return (0);
	}
	return (1);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	mbit;
	
	i = 0;
	size = ft_lstsize(*stack_a);
	mbit = maxbits(stack_a);
	while (i < mbits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a->content >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

t_stack	stackdup(t_stack **stack_a)
{
	t_stack	**new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	stacknew(
	return (copy);
}
