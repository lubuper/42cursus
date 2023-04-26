/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:10:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/26 18:41:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_game *game, t_img *img)
{
	game->mlx = 0;
	game->win = 0;
	game->addr = 0;
	game->map = 0;
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
	img->width = 16;
	img->height = 16;
	img->player = 0;
	img->floor = 0;
	img->wall = 0;
	img->exit = 0;
	img->collect = 0;
}

void	free_the_code(t_game *game, t_img *img)
{
	if (game->map)
		free(game->map);
	if (img)
	{
/*	mlx_destroy_image(game->mlx, IMG_WALL);
	mlx_destroy_image(game->mlx, IMG_PLAYER);
	mlx_destroy_image(game->mlx, IMG_COLLECT);
	mlx_destroy_image(game->mlx, IMG_FLOOR);
	mlx_destroy_image(game->mlx, IMG_EXIT);*/
	}
	exit (1);
}

int	close_win(t_game *game, t_img *img)
{
	mlx_destroy_window(game->mlx, game->win);
	free_the_code(game, img);
	return(0);
}

int	key_map(int keycode, t_game *game, t_img *img)
{
	if (keycode == ESC || keycode == M_CLICK_X)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_the_code(game, img);
	}
	else if (keycode == W)
		move_up(game, img);
	else if (keycode == S)
		move_down(game, img);
	else if (keycode == A)
		move_left(game, img);
	else if (keycode == D)
		move_right(game, img);
	return (0);
}
