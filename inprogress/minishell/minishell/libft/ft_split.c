/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:25:40 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/30 23:24:40 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stringcounter(const char *s, char c)
{
	int	i;
	int	nstrings;

	i = ft_strlen(s) - 1;
	nstrings = 0;
	while (i >= 0)
	{
		if (s[i] != c)
		{
			nstrings++;
			while (i > 0 && s[i] != c)
				i--;
		}
		if (s[i] == c)
			i--;
		if (i == 0)
			break ;
	}
	return (nstrings);
}

static int	ft_strlentoc(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		o;
	int		nofstrs;

	o = 0;
	if (!s)
		return (NULL);
	nofstrs = ft_stringcounter(s, c);
	result = malloc(sizeof(char *) * (nofstrs + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			result[o++] = ft_substr(s, 0, ft_strlentoc(s, c));
		while (*s && *s != c)
			s++;
	}
	result[o] = 0;
	return (result);
}
