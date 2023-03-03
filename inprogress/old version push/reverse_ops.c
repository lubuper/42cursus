/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:24 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/02 16:10:08 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack **stack_a)
{
	t_stack	*temp_stack;
	t_stack	*temp_endstack;
	t_stack	*temp_beforestack;

	if (!*stack_a)
		return ;
	temp_stack = *stack_a;
	temp_beforestack = santipenu(*stack_a);
	temp_endstack = slast(*stack_a);
	*stack_a = temp_endstack;
	(*stack_a)->next = temp_stack;
	temp_beforestack->next = NULL;
	ft_printf("rra");
}

void	rrotate_b(t_stack **stack_b)
{
	t_stack	*temp_stack;
	t_stack	*temp_endstack;
	t_stack	*temp_beforestack;

	if (!*stack_b)
		return ;
	temp_stack = *stack_b;
	temp_beforestack = santipenu(*stack_b);
	temp_endstack = slast(*stack_b);
	*stack_b = temp_endstack;
	(*stack_b)->next = temp_stack;
	temp_beforestack->next = NULL;
	ft_printf("rrb");
}

void	rr_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_stack;
	t_stack	*temp_endstack;
	t_stack	*temp_beforestack;

	if (!*stack_a || !*stack_b)
		return ;
	temp_stack = *stack_a;
	temp_beforestack = santipenu(*stack_a);
	temp_endstack = slast(*stack_a);
	*stack_a = temp_endstack;
	(*stack_a)->next = temp_stack;
	temp_beforestack->next = NULL;
	temp_stack = *stack_b;
	temp_beforestack = santipenu(*stack_b);
	temp_endstack = slast(*stack_b);
	*stack_b = temp_endstack;
	(*stack_b)->next = temp_stack;
	temp_beforestack->next = NULL;
	ft_printf("rrr");
}
