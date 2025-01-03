/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:13:39 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/05 23:13:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_img_l(t_game *game)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.wall, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.floor, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.playerl, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.collect, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit, game->x * 64, game->y * 64);
}

void	put_image_l(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			choose_img_l(game);
			game->x++;
		}
		game->y++;
	}
}

void	choose_img_r(t_game *game)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.wall, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.floor, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.playerr, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.collect, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit, game->x * 64, game->y * 64);
}

void	put_image_r(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			choose_img_r(game);
			game->x++;
		}
		game->y++;
	}
}
