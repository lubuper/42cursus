/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:16:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/07 18:46:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sstring;
	unsigned int	i;
	size_t	o;

	i = 0;
	o = 0;
	sstring = (char *)malloc(sizeof(*s) * (len + 1));
	if(!sstring)
		return (NULL);
	while(s[i])
	{
		if (i >= start && o < len)
		{
			sstring[o] = s[i];
			o++;
		}
		i++;
	}
	sstring[o] = 0;	
	return(sstring);
}

int	main(void)
{
	const char	str[] = "This is a test";
	unsigned int	i;
	size_t		size;

	i = 6;
	size = 11;
	printf("%s\n", ft_substr(str, i, size));
	return (0);
}
