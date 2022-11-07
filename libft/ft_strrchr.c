/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:40:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/05 12:59:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i != 0)
	{
		if (s[i] == c)
			return (s);
	i--;
	}
}
/*
int	main(void)
{
	char	str[] = "this is a test";

	printf("%s\n", ft_strrchr(str, 105));
	return (0);
}*/
