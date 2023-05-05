/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:10:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 21:38:39 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
	game->addr = 0;
	game->map = 0;
	game->mapd = 0;
	game->lines = 0;
	game->cols = 0;
	game->x = 0;
	game->px = 0;
	game->y = 0;
	game->py = 0;
	game->bits_per_pixel = 0;
	game->line_length = 0;
	game->endian = 0;
	game->moves = 0;
	game->cs = 0;
	game->flag = 0;
	init_imgs(game);
}

void	destroy_imgs(t_game *game)
{
		mlx_destroy_image(game->mlx, game->i.playerl);
		mlx_destroy_image(game->mlx, game->i.playerr);
		mlx_destroy_image(game->mlx, game->i.player);
		mlx_destroy_image(game->mlx, game->i.floor);
		mlx_destroy_image(game->mlx, game->i.wall);
		mlx_destroy_image(game->mlx, game->i.exit);
		mlx_destroy_image(game->mlx, game->i.collect);
		mlx_destroy_image(game->mlx, game->i.mob);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
}

void	free_the_code(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->lines)
		{
			free(game->mapd[i]);
			free(game->map[i++]);
		}
		free(game->map);
		free(game->mapd);
	}
	if (game->mlx)
		destroy_imgs(game);
	exit (1);
}

int	close_win(t_game *game)
{
	free_the_code(game);
	return (0);
}

int	key_map(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == M_CLICK_X)
		free_the_code(game);
	else if (keycode == W)
		move_up(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == D)
		move_right(game);
	return (0);
}
