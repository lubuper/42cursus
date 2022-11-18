/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:16:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 20:28:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	j;
	size_t			o;

	j = 0;
	o = 0;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[j])
	{
		if (j >= start && o < len)
		{
			sub[o] = s[j];
			o++;
		}
		j++;
	}
	sub[o] = 0;
	return (sub);
}
/*
int	main(void)
{
	const char	str[] = "This is a test";
	unsigned int	i;
	size_t		size;

	i = 5;
	size = 11;
	puts(ft_substr(str, i, size));
	return (0);
}*/
