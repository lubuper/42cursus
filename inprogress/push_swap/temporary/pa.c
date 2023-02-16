/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:01:23 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/13 20:21:10 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	temp;

	if (!stack_b)
		return ;
	temp = stack_b->content;
	stack_a->content = temp;
	stack_b->content = stack_b->next->content;
}
