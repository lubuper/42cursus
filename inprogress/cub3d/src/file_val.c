/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/10 17:24:42 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_mapfile(char **av)
{
	int	sufixp;
	int	fd;

	if (!av[1])
	{
		perror("Error\nNo scene description file!\n");
		exit(1);
	}
	sufixp = ft_strlen(av[1]) - 4;
	if (ft_strncmp(&av[1][sufixp], ".cub", 4))
	{
		perror("Error\nInvalid file type!\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nMap file empty!\n");
		close(fd);
		exit(1);
	}
	else
		return (0);
}

