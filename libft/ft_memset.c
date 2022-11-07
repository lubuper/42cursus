/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:58:22 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/05 12:05:33 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <string.h>
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*top;

	top = s;
	i = 0;
	while (i < n)
	{
		top[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int		t;
	char	a[] = "its a test";

	t = 32;

	printf("%s\n", (char *)ft_memset(a, t, 6));
	printf("%s\n", (char *)memset(a, t, 6));
	return (0);
}*/
