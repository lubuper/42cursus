/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/23 22:09:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*fixed_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		fixed_str[fd] = funcaodeirbuscar(fd, fixed_str);
	if (!fixed_str)
		return (NULL);
	line = get_line(fixed_str);
	fixed_str = ft_save(fixed_str);
	return (line);
}

void	readnsave(int fd, char *str)
{
	char	*sample;
	int		bytesread;

	if (ft_strchr(str, '\n'))
		return (str);
	sample = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!sample)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(str, '\n') && bytesread > 0)
	{
		bytesread = read(fd, sample, BUFFER_SUZE);
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
