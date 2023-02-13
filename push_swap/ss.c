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

void	ss(t_list **list_a, t_list **list_b)
{
	int	temp;

	if (!list_a->next || !*list_a  || !list_b->next || !*list_b)
		return ;
	temp = list_a->next->content;
	list_a->next->content = list_a->content;
	list_a->content = temp;
	temp = list_b->next->content;
	list_b->next->content = list_b->content;
	list_b->content = temp;

	return ;
}
