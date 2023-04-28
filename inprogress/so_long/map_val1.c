/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:46:00 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/28 20:19:13 by lde-sous         ###   ########.fr       */
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

void	valid_shape(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines - 2)
	{
		if (ft_strlen(game->map[game->y]) != ft_strlen(game->map[game->y + 1])
			|| game->cols == game->lines)
		{
			ft_printf("Error: invalid map shape\n");
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
			ft_printf("Error: walls are not in place\n");
			free_the_code(game);
		}
		game->y++;
	}
	while (game->x < game->cols)
	{
		if (game->map[0][game->x] != game->map[game->lines - 1][game->x])
		{
			ft_printf("Error: walls are not in place\n");
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
	game->cols = ft_strlen(get_next_line(fd, true));
	close(fd);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, true) != 0)
		game->lines++;
	close(fd);
	game->map = malloc(sizeof(char *) * game->lines);
	if (!game->map)
		free_the_code(game);
	fd = open(av[1], O_RDONLY);
	rows = game->lines;
	while (rows-- > 0)
		game->map[game->y++] = get_next_line(fd, true);
	close(fd);
	negate_n(game);
	game->cols--;
	valid_shape(game);
	valid_walls(game);
	check_map(game);
}
