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

void	sa(t_list *list_a)
{
	int	temp;

	if (!list_a->next || !list_a)
		return ;
	temp = list_a->next->content;
	list_a->next->content = list_a->content;
	list_a->content = temp;
	return ;
}
