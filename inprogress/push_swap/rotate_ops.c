/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:45:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/22 17:34:48 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	t_stack	*temp_s;

	if (!stack_a)
		return ;
	temp_s = stacknew(stack_a->content);
	while (stack_a->next != NULL)
	{
		stack_a->content = stack_a->next->content;
	}
	stack_a->next = temp_s;
	ft_printf("ra");
}

void	rotate_b(t_stack *stack_b)
{
	t_stack	*temp_s;

	if (!stack_b)
		return ;
	temp_s = stacknew(stack_b->content);
	while (stack_b->next != NULL)
	{
		stack_b->content = stack_b->next->content;
	}
	stack_b->next = temp_s;
	ft_printf("rb");
}

void	rotate_rotate(t_stack *stack_a, t_stack_ *stack_b)
{
	t_stack	*temp;

	if (!stack_a || !stack_b)
		return ;
	temp_s = stacknew(stack_a->content);
	while (stack_a->next != NULL)
	{
		stack_a->content = stack_a->next->content;
	}
	stack_a->next = temp_s;
	temp_s = stacknew(stack_b->content);
	while (stack_b->next != NULL)
	{
		stack_b->content = stack_b->next->content;
	}
	stack_b->next = temp_s;
	ft_printf("rr");
}
