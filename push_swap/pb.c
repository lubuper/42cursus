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

void	pb(t_list list_a, t_list list_b)
{
	int	temp;
	if(!list_a)
		return ;
	temp = list_a->content;
	list_b->content = temp;
	list_a->content = list_a->next;
}
