/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:33:36 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/11 19:01:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	v;

	i = 0;
	v = 0;
	while (s1[v])
	{
		while (s2[i])
		{
			if (s2[i] == s1[v])
				return ((char *)s1 + v);
			i++;
		}
		i = 0;
		v++;
	}

	return (NULL);
}

int	main(void)
{
	char	*verify;
	char	*base;

	verify = "this is a string";
	base = "abcdef";
	printf("%s\n", ft_strpbrk(verify, base));
}
