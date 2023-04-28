/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:41:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/28 21:41:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_printf("Cs = %d\n", game->cs);
	ft_printf("player at %d, %d\n", game->px, game->py);
}

void	final_checks(t_game *game)
{
	startpos(game);
}
