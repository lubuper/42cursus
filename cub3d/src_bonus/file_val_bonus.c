/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_val_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 17:07:06 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	valid_file(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nInvalid number of arguments!\n");
		exit(1);
	}
	check_mapfile(av);
}

void	check_mapfile(char **av)
{
	int	sufixp;
	int	fd;

	if (!av[1])
	{
		printf("Error\nNo scene description file!\n");
		exit(1);
	}
	sufixp = ft_strlen(av[1]) - 4;
	if (ft_strncmp(&av[1][sufixp], ".cub", 4))
	{
		printf("Error\nInvalid file type!\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nMap file empty!\n");
		exit(1);
	}
	else
		close(fd);
}

void	pixel_to_scr(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->i.addr + (y * d->i.line_len + x * (d->i.bpp / 8));
	*(unsigned int *)dst = color;
}
