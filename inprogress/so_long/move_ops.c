/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/28 21:40:31 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moving(t_game *game)
{
	if (game->map[game->py][game->px] == '1')
	{
		game->py += 1;
		return ;
	}
	else if (game->map[game->py][game->px] == 'C')
		game->cs--;
	else if (game->map[game->py][game->px] == 'E')
	{
		if (game->cs == 0)
		{
			ft_printf("Congratulations! Level Complete!");
			free_the_code(game);
		}
	}
}

void	move_up(t_game *game)
{
	game->py -= 1;
	moving(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.floor, game->px * 16, (game->py + 1) * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_down(t_game *game)
{
	game->py += 1;
	moving(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.floor, game->px * 16, (game->py - 1) * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_left(t_game *game)
{
	game->px -= 1;
	moving(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.floor, (game->px + 1) * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_right(t_game *game)
{
	game->px += 1;
	moving(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.floor, (game->px - 1) * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		game->i.player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}
