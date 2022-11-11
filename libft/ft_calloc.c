/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:15:17 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/10 16:05:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tempvector;
	size_t		i;

	i = 0;
	tempvector = malloc(sizeof(nmemb) * (size + 1));
	if (!tempvector)
		return (NULL);
	while (i < nmemb * size)
	{
		tempvector[i] = '\0';
		i++;
	}
	return (tempvector);
}
