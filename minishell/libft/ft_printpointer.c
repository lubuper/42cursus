/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 06:11:03 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_loncount(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_printaux(unsigned long to_hex)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (to_hex >= 16)
	{
		ft_printaux(to_hex / 16);
		ft_printaux(to_hex % 16);
	}
	if (to_hex < 16)
		ft_printchar(hexbase[to_hex]);
	return (1);
}

int	ft_printpointer(unsigned long point)
{
	if (!point)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_printaux(point);
	return (ft_loncount(point) + 2);
}
