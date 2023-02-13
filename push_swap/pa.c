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

void	pa(t_list **list_a, t_list **list_b)
{
	int	temp;
	if (!list_b)
		return ;
	temp = list_b->content;
	list_a->content = temp;
	list_b->content = list_b->next;
}
