/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:41:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/09 14:01:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->lines)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!(game->map[y][x] == '1' || game->map[y][x] == '0'
				|| game->map[y][x] == 'P' || game->map[y][x] == 'C'
					|| game->map[y][x] == 'E'))
			{
				ft_putstr_fd("Error\nInvalid map element!\n", 2);
				free_the_code(game);
			}
			x++;
		}
	}
	if (ecount(game, 'P') != 1 || ecount(game, 'E') != 1
		|| ecount(game, 'C') < 1)
	{
		ft_putstr_fd("Error\nInvalid number of map elements!\n", 2);
		free_the_code(game);
	}
}

int	valid_path(t_game *game, char **map, int y, int x)
{
	static int	wayout;
	static int	pickup;

	if (map[y][x] == 'E')
	{
		wayout = 1;
		return (0);
	}
	if (map[y][x] == 'C')
		pickup++;
	if (map[y][x] == '1' || x > game->cols
			|| y > game->lines || map[y][x] == 'V')
		return (0);
	map[y][x] = 'V';
	valid_path(game, game->mapd, y + 1, x);
	valid_path(game, game->mapd, y - 1, x);
	valid_path(game, game->mapd, y, x + 1);
	valid_path(game, game->mapd, y, x - 1);
	if (wayout == 1 && pickup == game->cs)
		return (1);
	else
		return (0);
}

void	startpos(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == 'P')
			{
				game->px = game->x;
				game->py = game->y;
			}
			game->x++;
		}
			game->y++;
	}
	game->cs = ecount(game, 'C');
}

void	moving_checks(t_game *game)
{
	if (game->map[game->py][game->px] == 'C')
	{
		game->cs--;
		game->map[game->py][game->px] = '0';
	}
	else if (game->map[game->py][game->px] == 'E')
	{
		if (game->cs == 0)
		{
			ft_printf("Congratulations! Level Complete!\n");
			free_the_code(game);
		}
	}
}

void	final_checks(t_game *game)
{
	startpos(game);
	if (valid_path(game, game->mapd, game->py, game->px) == 0)
	{
		ft_putstr_fd("Error\nMap exit unreachable!\n", 2);
		free_the_code(game);
	}
}
