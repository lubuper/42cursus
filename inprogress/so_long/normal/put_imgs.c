/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/01 14:13:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_i(t_game *game)
{
	game->i.wall = mlx_xpm_file_to_image(game->mlx, I_WALL,
			&game->i.width, &game->i.height);
	game->i.player = mlx_xpm_file_to_image(game->mlx, I_PLAYER,
			&game->i.width, &game->i.height);
	game->i.collect = mlx_xpm_file_to_image(game->mlx, I_COLLECT,
			&game->i.width, &game->i.height);
	game->i.floor = mlx_xpm_file_to_image(game->mlx, I_FLOOR,
			&game->i.width, &game->i.height);
	game->i.exit = mlx_xpm_file_to_image(game->mlx, I_EXIT,
			&game->i.width, &game->i.height);
}

void	choose_img(t_game *game)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.wall, game->x * 16, game->y * 16);
	else if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.floor, game->x * 16, game->y * 16);
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.player, game->x * 16, game->y * 16);
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.collect, game->x * 16, game->y * 16);
	else if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit, game->x * 16, game->y * 16);
}

void	put_image(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			choose_img(game);
			game->x++;
		}
		game->y++;
	}
}
