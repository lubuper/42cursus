/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:46:00 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/02 20:39:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_mapfile(char **av)
{
	int	sufixp;
	int	fd;

	if (!av[1])
	{
		ft_putstr_fd("Error\nNo map file!\n", 2);
		exit(1);
	}
	sufixp = ft_strlen(av[1]) - 4;
	if (ft_strncmp(&av[1][sufixp], ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid map file!\n", 2);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nMap file empty!\n", 2);
		exit(1);
	}
	else
		return (0);
}

void	valid_shape(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines - 2)
	{
		if (ft_strlen(game->map[game->y]) != ft_strlen(game->map[game->y + 1])
			|| game->cols == game->lines)
		{
			ft_putstr_fd("Error\nInvalid map shape!\n", 2);
			free_the_code(game);
		}
		game->y++;
	}
}

void	valid_walls(t_game *game)
{
	game->y = 0;
	game->x = 0;
	while (game->y < game->lines)
	{
		if (game->map[game->y][0] != game->map[game->y][game->cols - 1])
		{
			ft_putstr_fd("Error\nWalls are not in place!\n", 2);
			free_the_code(game);
		}
		game->y++;
	}
	while (game->x < game->cols)
	{
		if (game->map[0][game->x] != game->map[game->lines - 1][game->x])
		{
			ft_putstr_fd("Error\nWalls are not in place!\n", 2);
			free_the_code(game);
		}
		game->x++;
	}
}

void	negate_n(t_game *game)
{
	int	lines;
	int	y;

	lines = game->lines;
	y = 0;
	while (lines-- < 0)
		game->map[y++][game->cols - 1] = 0;
}

void	hold_map_m(t_game *game, char **av)
{
	int	fd;
	int	rows;

	game->y = 0;
	game->lines = 0;
	fd = open(av[1], O_RDONLY);
	game->cols = gnllen(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
		game->lines = gnllines(fd);
	close(fd);
	game->map = malloc(sizeof(char *) * game->lines);
	if (!game->map)
		free_the_code(game);
	fd = open(av[1], O_RDONLY);
	rows = game->lines;
	gnlfreed(game, fd);
	close(fd);
	negate_n(game);
	game->cols--;
	valid_shape(game);
	valid_walls(game);
	check_map(game);
}
