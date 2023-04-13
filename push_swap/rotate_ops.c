/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:45:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/03/02 16:08:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	int		temp;
	t_stack	*temporary;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->content;
	temporary = *stack_a;
	while (temporary->next != NULL)
	{
		temporary->content = temporary->next->content;
		temporary = temporary->next;
	}
	temporary->content = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	int		temp;
	t_stack	*temporary;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->content;
	temporary = *stack_b;
	while (temporary->next != NULL)
	{
		temporary->content = temporary->next->content;
		temporary = temporary->next;
	}
	temporary->content = temp;
	ft_printf("rb\n");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int		temp;
	t_stack	*temporary;

	if (!*stack_a || !*stack_b)
		return ;
	temp = (*stack_a)->content;
	temporary = *stack_a;
	while (temporary->next != NULL)
	{
		temporary->content = temporary->next->content;
		temporary = temporary->next;
	}
	temporary->content = temp;
	temp = (*stack_b)->content;
	temporary = *stack_b;
	while (temporary->next != NULL)
	{
		temporary->content = temporary->next->content;
		temporary = temporary->next;
	}
	temporary->content = temp;
	ft_printf("rr\n");
}
