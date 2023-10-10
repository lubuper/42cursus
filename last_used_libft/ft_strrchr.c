/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/02 21:42:07 by lde-sous         ###   ########.fr       */
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
		if ((unsigned char)s[i] == (unsigned char)c)
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
