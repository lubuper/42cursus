/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/01 14:13:30 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	game->i.mob = mlx_xpm_file_to_image(game->mlx, I_MOB,
		&game->i.width, &game->i.height);
}

/*char	premove(t_game *game)
{
	
}

void	put_player(t_game *game)
{
	if (!premove)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.splayer, game->x * 16, game->y * 16);
	else if (premove == 'W')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.wplayer, game->x * 16, game->y * 16);
	else if (premove == 'A')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.aplayer, game->x * 16, game->y * 16);
	else if (premove == 'S')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.splayer, game->x * 16, game->y * 16);
	else if (premove == 'D')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.dplayer, game->x * 16, game->y * 16);
}*/

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
	else if (game->map[game->y][game->x] == 'M')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.mob, game->x * 16, game->y * 16);
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
