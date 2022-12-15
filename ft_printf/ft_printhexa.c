/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:21 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/15 17:09:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long to_hex, char s)
{
	int		count;
	char	*hexbase;

	count = 0;
	if (s == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (to_hex <= 16)
		count += ft_printchar(hexbase[to_hex]);
	else
	{
		count += ft_printhexa(to_hex / 16, s);
		to_hex = (to_hex % 16);
	}
	return (count);
}
