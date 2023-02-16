/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:08:09 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/16 16:16:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	temp;
	if(!stack_a->next || !stack_a)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
}

void	swap_b(t_stack *stack_b)
{
	int	temp;
	if(!stack_b->next || !stack_b)
		return ;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
