/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:47 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 18:13:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	sdup = (char *)malloc(sizeof(*s) + ft_strlen(s) +1);
	if (!sdup)
		return (NULL);
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}
