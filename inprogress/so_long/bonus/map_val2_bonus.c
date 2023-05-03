/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:41:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/01 15:44:44 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (game->map[game->py][game->px] == 'M')
	{
		ft_printf("GAME OVER! Try again!\n");
		free_the_code(game);
	}
}

void	final_checks(t_game *game)
{
	startpos(game);
}
