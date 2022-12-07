/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:02:57 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/07 12:56:59 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return ((char *)&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
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
	if (!str1 || !str2)
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

/* main para testar str_join_mod
int	main(void)
{
	char	s1[] = "This is ";
	char	s2[] = "A TESSTTT!!!!!";
	printf("%s", "s1 = ");
	printf("%s\n", s1);
	printf("%s", "s2 = ");
	printf("%s\n\n", s2);
	printf("%s", "str_join_mod = ");
	printf("%s\n", str_join_mod(s1, s2));
	return (0);
}*/
