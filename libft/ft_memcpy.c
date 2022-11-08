/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:31:14 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/08 11:52:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	unsigned char	a[] = "0";
	unsigned char	b[] = "This is the source";
	unsigned char	c[] = "0";
	unsigned char	d[] = "This is the source";

	puts((char *)ft_memcpy(a, b, 8));
	puts((char *)memcpy(c, d, 8));
	return (0);
}*/
