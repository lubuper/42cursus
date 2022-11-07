/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:53:41 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 15:07:19 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	while (dst[i])
		i++;
	while (o < (size - 1) && src[o])
	{
		dst[i] = src[o];
		o++;
	}
	while (o < size)
	{
		dst[i] = '\0';
		o++;
	}
	return (i + o);
}
