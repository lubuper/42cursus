/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 17:16:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	moving_walls(t_game *game)
{
	if (game->flag == 1)
		game->py += 1;
	else if (game->flag == 2)
		game->py -= 1;
	else if (game->flag == 3)
		game->px += 1;
	else if (game->flag == 4)
		game->px -= 1;
	return ;
}

void	move_up(t_game *game)
{
	game->py -= 1;
	game->flag = 1;
	if (game->map[game->py][game->px] == '1' ||
		(game->map[game->py][game->px] == 'E' && game->cs > 0))
		moving_walls(game);
	else
	{
		moving_checks(game);
		game->moves++;
		game->map[game->py][game->px] = 'P';
		game->map[game->py + 1][game->px] = '0';
		is_mob(game);
		put_image(game);
		ft_printf("Move count = %d\n", game->moves);
	}
}

void	move_down(t_game *game)
{
	game->py += 1;
	game->flag = 2;
	if (game->map[game->py][game->px] == '1' ||
		(game->map[game->py][game->px] == 'E' && game->cs > 0))
		moving_walls(game);
	else
	{
		moving_checks(game);
		game->moves++;
		game->map[game->py][game->px] = 'P';
		game->map[game->py - 1][game->px] = '0';
		is_mob(game);
		put_image(game);
		ft_printf("Move count = %d\n", game->moves);
	}
}

void	move_left(t_game *game)
{
	game->px -= 1;
	game->flag = 3;
	if (game->map[game->py][game->px] == '1' ||
		(game->map[game->py][game->px] == 'E' && game->cs > 0))
		moving_walls(game);
	else
	{
		moving_checks(game);
		game->moves++;
		game->map[game->py][game->px] = 'P';
		game->map[game->py][game->px + 1] = '0';
		is_mob(game);
		put_image(game);
		ft_printf("Move count = %d\n", game->moves);
	}
}

void	move_right(t_game *game)
{
	game->px += 1;
	game->flag = 4;
	if (game->map[game->py][game->px] == '1' ||
		(game->map[game->py][game->px] == 'E' && game->cs > 0))
		moving_walls(game);
	else
	{
		moving_checks(game);
		game->moves++;
		game->map[game->py][game->px] = 'P';
		game->map[game->py][game->px - 1] = '0';
		is_mob(game);
		put_image(game);
		ft_printf("Move count = %d\n", game->moves);
	}
}
