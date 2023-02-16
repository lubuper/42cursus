/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:17:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/15 13:20:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ra(t_stack **stack_a)
{
	int	*temp;
	int	*help;

	if (!stack_a)
		return ;
	if (stack_a)
	{
		while (stack_a->next != NULL)
		
		
		stack_a = stack_a->next;
}
		
	temp = stack_a->content;
	stack_a->next->content = temp;
	stack_a->content = stack_b->next;
}
