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
int	maxdigits(t_stack **stack)
{
	int	n;
	int	max_e;

	max_e = (*stack)->content;
	n = 0;
	while ((*stack)->next)
	{
		if (max_e < (*stack)->content)
			max_e = (*stack)->content;
		stack = (*stack)->next;
	}
	while (max_e)
	{
		max_e /= 10;
		n++;
	}
	return (n);
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

t_stack	stackdup(t_stack **stack_a)
{
	stacknew(
	return (copy);
}
