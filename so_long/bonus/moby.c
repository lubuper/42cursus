/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moby.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:18 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/10 11:21:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
