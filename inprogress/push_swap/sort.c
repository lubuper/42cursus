/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:52:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/22 18:37:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	
}
*/
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

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element;

	element = *stack_a;
	while (element->next != 0)
	{
		ft_printf("is_sorted in while loop\n");
		if (element->content > element->next->content && !(*stack_b))
			return (0);
		element = element->next;
	}
	return (1);
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

/*t_stack	stackdup(t_stack **stack_a)
{
	t_stack	**new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	stacknew(
	return (copy);
}*/
