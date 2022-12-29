/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:55:06 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/02 11:04:47 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stringcounter(const char *s, char c)
{
	int	i;
	int	nstrings;

	i = 0;
	nstrings = 0;
	while (s[i])
	{
		i++;
		if (s[i] && s[i] == c && s[i + 1] != c)
			nstrings++;
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
/*
int	main(void)
{
	char	*c = "s ola   o meu nome e luis ";
	char	s = 32;
	int	i = 0;
	char	**temp;
	temp = ft_split(c, s);
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
}*/
