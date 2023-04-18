/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:46:00 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/17 19:46:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapfile(char **av)
{
	int	sufixp;
	int	fd;

	if (!av[1])
	{
		ft_printf("Error: no map file\n");
		exit(1);
	}
	sufixp = ft_strlen(av[1]) - 4;
	if (ft_strncmp(&av[1][sufixp], ".ber", 4))
	{
		ft_printf("Error: invalid map file\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: map file empty\n");
		exit(1);
	}
	else
		return (0);
}

void	valid_shape(t_game game)
{
	game.y = 0;
	while (game.y < game.lines - 1)
	{
		if (ft_strlen(game.map[game.y]) != ft_strlen(game.map[game.y + 1])
			|| game.cols == game.lines)
		{
			ft_printf("Error: invalid map shape\n");
			exit(1);
		}
		game.y++;
	}
}

void	hold_map_m(t_game game, char **av)
{
	int	fd;
	int	rows;

	game.y = 0;
	game.lines = 0;
	fd = open(av[1], O_RDONLY);
	game.cols = ft_strlen(get_next_line(fd)) - 1;
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd) != 0)
		game.lines++;
	close(fd);
	game.map = malloc(sizeof(char *) * --game.lines);
	fd = open(av[1], O_RDONLY);
	rows = game.lines;
	while (rows-- >= 0)
		game.map[game.y++] = get_next_line(fd);
	close(fd);
	valid_shape(game);
	valid_walls(game);
}

void	valid_walls(t_game game)
{
	game.y = 0;
	game.x = 0;
	while (game.y <= game.lines)
	{
		if (game.map[game.y][0] != game.map[game.y][game.cols - 1])
		{
			ft_printf("Error: walls are not in place\n");
			exit(1);
		}
		game.y++;
	}
	while (game.x < game.cols)
	{
		if (game.map[0][game.x] != game.map[game.lines][game.x])
		{
			ft_printf("Error: walls are not in place\n");
			exit(1);
		}
		game.x++;
	}
}
