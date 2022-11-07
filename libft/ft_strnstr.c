/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:04:38 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 12:42:26 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"
#include <stdio.h>
#include <string.h>
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	if (!little[o])
		return ((char *)big);
	while (big[i] && i < (len - 1))
	{
		while (big[i + o] == little[o] && big[i + o])
			o++;
		if (!little[o])
			return ((char *)big + i);
		i++;
	}
		o = 0;
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "Those hi were tests";
	char	s2[] = "hi";

	//printf("%s\n", strnstr(s1, s2, 10));
	printf("%s\n", ft_strnstr(s1, s2, 10));
	return (0);
}*/
