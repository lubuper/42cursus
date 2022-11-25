/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/25 16:33:13 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*outline;
	static char	*fixed_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fixed_str = readnsave(fd, fixed_str);
	if (!fixed_str)
		return (NULL);
	outline = ft_gline(fixed_str);
	fixed_str = save_rest(fixed_str);
	return (outline);
}

char	*readnsave(int fd, char *str)
{
	char	*sample;
	int		bytesread;

	if (ft_strchr_mod(str, '\n'))
		return (str);
	sample = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!sample)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr_mod(str, '\n') && bytesread > 0)
	{
		bytesread = read(fd, sample, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(sample);
			return (NULL);
		}
		sample[bytesread] = 0;
		str = str_join_mod(str, sample);
	}
	free(sample);
	return (str);
}

char	*ft_gline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	free(str);
	return (line);
}

char	*save_rest(char *str)
{
	int		i;
	int		j;
	char	*saved_trim;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	saved_trim = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (str[i])
	{
		saved_trim[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (saved_trim);
}
