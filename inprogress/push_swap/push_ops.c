/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:30:50 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/16 15:18:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new;

	if (!stack_b)
		return ;
	new = stacknew(stack_b->content);
	saddfront(stack_a, new);

	while (stack_b->next != NULL)
		stack_b->content = stack_b->next->content;
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*new;

	if (!stack_a)
		return ;
	new = stacknew(stack_a->content);
	saddfront(stack_b, new);

	while (stack_a->next != NULL)
		stack_a->content = stack_a->next->content;
}
