/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:02:27 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/25 17:10:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

/* 	fd = open("tests/testa.txt", O_RDONLY);
	fd = open("tests/testb.txt", O_RDONLY); */
	fd = open("tests/testc.txt", O_RDONLY);
/* 	fd = open("tests/testd.txt", O_RDONLY);
	fd = open("tests/teste", O_RDONLY);
	fd = open("tests/testf", O_RDONLY); */
	i = 1;
	printf("%d", fd);
	while ((line = get_next_line(fd)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
