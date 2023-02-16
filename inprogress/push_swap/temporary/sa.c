/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:27:46 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/13 19:46:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	sa(t_stack **stack_a)
{
	int	*temp;

	if (!stack_a->next || !stack_a)
		return ;
	temp = stack_a->next->content;
	stack_a->next->content = stack_a->content;
	stack_a->content = temp;
	return ;
}
