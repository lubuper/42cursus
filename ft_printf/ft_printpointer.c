/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:27 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/15 14:31:35 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long point)
{
	int		count;
	char	*pre;

	if (!point)
		return (write(1, "(nill)", 1));
	pre = "0x";
	ft_printstring(pre);
	count = 2 + ft_printhexa(point, 'x');
	return (count);
}
