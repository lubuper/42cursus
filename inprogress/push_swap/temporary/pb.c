/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:10:41 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/13 20:12:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	pb(t_stack stack_a, t_stack stack_b)
{
	int	temp;

	if (!stack_a)
		return ;
	temp = stack_a->content;
	stack_b->content = temp;
	stack_a->content = stack_a->next;
}
