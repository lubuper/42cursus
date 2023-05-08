/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:43:59 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 21:11:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mob_v(t_game *game)
{
	if (game->flag == 1)
		game->my += 1;
	else if (game->flag == 2)
		game->my -= 1;
	else if (game->flag == 3)
		game->mx += 1;
	else if (game->flag == 4)
		game->mx -= 1;
	return ;
}

void	mob_up(t_game *game)
{
	game->my -= 1;
	game->flag = 1;
	if (game->map[game->my][game->mx] == '1' ||
		game->map[game->my][game->mx] == 'E' ||
			game->map[game->my][game->mx] == 'C' ||
				game->map[game->my][game->mx] == 'M')
	{
		mob_v(game);
	}
	else if (game->map[game->my][game->mx] == 'P')
	{
		ft_printf("GAME OVER! Try again!\n");
		free_the_code(game);
	}
	else
	{
		game->map[game->my][game->mx] = 'M';
		game->map[game->my + 1][game->mx] = '0';
	}
}

void	mob_dn(t_game *game)
{
	game->my += 1;
	game->flag = 2;
	if (game->map[game->my][game->mx] == '1' ||
		game->map[game->my][game->mx] == 'E' ||
			game->map[game->my][game->mx] == 'C' ||
				game->map[game->my][game->mx] == 'M')
	{
		mob_v(game);
	}
	else if (game->map[game->my][game->mx] == 'P')
	{
		ft_printf("GAME OVER! Try again!\n");
		free_the_code(game);
	}
	else
	{
		game->map[game->my][game->mx] = 'M';
		game->map[game->my - 1][game->mx] = '0';
	}
}

void	mob_l(t_game *game)
{
	game->mx -= 1;
	game->flag = 3;
	if (game->map[game->my][game->mx] == '1' ||
		game->map[game->my][game->mx] == 'E' ||
			game->map[game->my][game->mx] == 'C' ||
				game->map[game->my][game->mx] == 'M')
	{
		mob_v(game);
	}
	else if (game->map[game->my][game->mx] == 'P')
	{
		ft_printf("GAME OVER! Try again!\n");
		free_the_code(game);
	}
	else
	{
		game->map[game->my][game->mx] = 'M';
		game->map[game->my][game->mx + 1] = '0';
	}
}

void	mob_r(t_game *game)
{
	game->mx += 1;
	game->flag = 4;
	if (game->map[game->my][game->mx] == '1' ||
		game->map[game->my][game->mx] == 'E' ||
			game->map[game->my][game->mx] == 'C' ||
				game->map[game->my][game->mx] == 'M')
	{
		mob_v(game);
	}
	else if (game->map[game->my][game->mx] == 'P')
	{
		ft_printf("GAME OVER! Try again!\n");
		free_the_code(game);
	}
	else
	{
		game->map[game->my][game->mx] = 'M';
		game->map[game->my][game->mx - 1] = '0';
	}
}

void	mob_move(t_game *game)
{
	int	dir;

	dir = rand () % 4;
	if (dir == 0)
		mob_up(game);
	else if (dir == 1)
		mob_dn(game);
	else if (dir == 2)
		mob_l(game);
	else if (dir == 3)
		mob_r(game);
}

void	is_mob(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == 'M')
			{
				game->my = game->y;
				game->mx = game->x;
				mob_move(game);
			}
			game->x++;
		}
		game->y++;
	}
}
