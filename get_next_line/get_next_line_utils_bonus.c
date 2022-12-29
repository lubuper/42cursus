/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:24:13 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/29 11:24:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_mod(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == 0)
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*str_join_mod(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*jointstr;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = 0;
	}
	if (!str1 && !str2)
		return (NULL);
	jointstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!jointstr)
		return (NULL);
	i = 0;
	j = 0;
	if (str1)
		while (str1[i])
			jointstr[i++] = str1[j++];
	j = 0;
	while (str2[j])
		jointstr[i++] = str2[j++];
	jointstr[ft_strlen(str1) + ft_strlen(str2)] = 0;
	free(str1);
	return (jointstr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*nulled_str;
	size_t			i;
	unsigned int	total;

	total = nmemb * size;
	i = 0;
	nulled_str = malloc(total);
	if (!nulled_str)
		return (NULL);
	while (total > 0)
	{
		nulled_str[i] = 0;
		total--;
		i++;
	}
	return ((void *)nulled_str);
}
