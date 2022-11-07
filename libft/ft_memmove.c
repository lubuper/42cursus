/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:12:25 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/05 12:31:43 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest2;
	char	*src2;
	char	*temp;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	temp = dest2;
	while (src2[i] && (i < n))
	{
		temp[i] = src2[i];
		i++;
	}
	dest2 = temp;
	return (dest2);
}
/*
int	main(void)
{
	char	a[] = "123456789";
	char	b[] = "may tests";

	printf("%s\n", (unsigned char *)ft_memmove(a, b, 8));
	printf("%s\n", (unsigned char *)memmove(a, b, 8));

	return (0);
}*/
