/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:55:00 by lde-sous          #+#    #+#             */
/*   Updated: 2023/01/11 16:07:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	j;
	size_t	counter;

	j = 0;
	counter = 0;
	while (s[counter])
	{
		while (reject[j] != s[counter] && reject[j])
			j++;
		if (reject[j] == s[counter])
			return (counter);
		j = 0;
		counter++;
	}
	return (counter);
}

int	main(void)
{
	char	*first;
	char	*not;

	first = "cabc";
	not = "zedc";
	printf("%zu\n", ft_strcspn(first, not));
	printf("%lu\n", strcspn(first, not));
}
