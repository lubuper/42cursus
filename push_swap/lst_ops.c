/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:30:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/30 12:53:03 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*slast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	saddback(t_stack *stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!stack)
	{
		stack = new;
		return ;
	}
	temp = slast(stack);
	temp->next = new;
}

t_stack	*santipenu(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stsize(t_stack *stack)
{
	int	size;

	size = 1;
	if (!stack)
		return (0);
	if (stack)
	{
		while (stack->next)
		{
			stack = stack->next;
			size++;
		}
	}
	return (size);
}

void	stclear(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
