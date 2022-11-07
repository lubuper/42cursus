/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:43:01 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 14:31:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;

	i = 0;
	while (s1[i] && s2[i] && (i < (n - 1)) && s1[i] == s2[i])
		i++;
	if (n == 0)
		return (0);
	else
		return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	a[] = "this is 2 a2st";
	char	b[] = "this is a 2tst";

	printf("%d\n", ft_strncmp(a, b, 13));
}*/