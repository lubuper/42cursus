/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:41:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/13 19:45:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	sb(t_list *list_b)
{
	int	temp;

	if (!list_b->next || !list_b)
		return ;
	temp = list_b->next->content;
	list_b->next->content = list_b->content;
	list_b->content = temp;
	return ;
}
