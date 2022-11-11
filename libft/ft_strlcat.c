/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:53:41 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/11 09:54:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	o;

	i = ft_strlen(dst);
	o = 0;
	if (i > size)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && src[o])
	{
		dst[i] = src[o];
		o++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[o]));
}
/*
int	main(void)
{
	char	str1[] = "Luis";
	char	str2[] = "Eduardo";
	printf("%zu\n", ft_strlcat(str1, str2, 13));
	puts(str1);
}*/
