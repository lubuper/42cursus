/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:36:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/12 20:07:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	bit;
	int	i;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = (bit << 1) | (octet % 2);
		i++;
		octet >>= 1;
	}
	return (bit);
}

int	main(void)
{
	printf("%c", reverse_bits((unsigned char)2));
	return (0);
}
