/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:43:00 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/13 19:45:26 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	if (!stack_a->next || !*stack_a || !stack_b->next || !*stack_b)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
	temp = stack_b->next->content;
	stack_b->next->content = stack_b->content;
	stack_b->content = temp;
	return ;
}
