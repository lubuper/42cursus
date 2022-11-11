/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/11 11:09:56 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i])
	{
		i++;
		str++;
	}
	while (i >= 0)
	{
		if (s[i] == c)
			return (str);
	i--;
	str--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "this is a test";

	printf("%s\n", ft_strrchr(str, 105));
	return (0);
}*/
