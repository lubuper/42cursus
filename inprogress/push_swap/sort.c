/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:52:19 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/29 18:36:12 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	swap_a(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		swap_a(stack_a);
	else if ((*stack_a)->next->content < (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		swap_a(stack_a);
		rrotate_a(stack_a);
	}
	else if ((*stack_a)->next->next->content > (*stack_a)->next->content
		&& (*stack_a)->next->next->content < (*stack_a)->content)
		rotate_a(stack_a);
	else if ((*stack_a)->next->next->content < (*stack_a)->next->content
		&& (*stack_a)->next->next->content > (*stack_a)->content)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rrotate_a(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	if (is_sorted(stack_a, stack_b) == 0)
	{
		rotate_a(stack_a);
		sort_four(stack_a, stack_b);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
/*	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	rotate_a(stack_a);
	push_a(stack_a, stack_b);
	while (is_sorted(stack_a, stack_b) == 0)
	{
		rotate_a(stack_a);
		push_b(stack_b, stack_a);
		push_b(stack_b, stack_a);
		sort_three(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}*/
	radix(stack_a, stack_b);
}
