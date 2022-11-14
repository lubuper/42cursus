/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:43:01 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 11:53:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (n == 0 || n == i)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	a[] = "this is 2 a2st";
	char	b[] = "this is a 2tst";

	printf("%d\n", ft_strncmp(a, b, 13));
}*/
