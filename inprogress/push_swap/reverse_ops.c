/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:38:24 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/22 17:56:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stack *stack_a)
{
	t_stack	*temp_s

	if (!stack_a)
		return ;
	temp_s = slast(stack_a);
	while (stack->next != NULL)
		stack_a->next->content = stack_a->content;
	saddback(stack_a, temp_s);
	ft_printf("rra")
}

void	rrotate_b(t_stack *stack_b)
{
	t_stack	*temp_s

	if (!stack_b)
		return ;
	temp_s = slast(stack_b);
	while (stack->next != NULL)
		stack_a->next->content = stack_b->content;
	saddback(stack_b, temp_s);
	ft_printf("rrb")
}
