/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/09 13:56:42 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_i(t_game *game)
{
	game->i.wall = mlx_xpm_file_to_image(game->mlx, I_WALL,
			&game->i.width, &game->i.height);
	game->i.player = mlx_xpm_file_to_image(game->mlx, I_PLAYER,
			&game->i.width, &game->i.height);
	game->i.playerl = mlx_xpm_file_to_image(game->mlx, I_PLAYERL,
			&game->i.width, &game->i.height);
	game->i.playerr = mlx_xpm_file_to_image(game->mlx, I_PLAYERR,
			&game->i.width, &game->i.height);
	game->i.collect = mlx_xpm_file_to_image(game->mlx, I_COLLECT,
			&game->i.width, &game->i.height);
	game->i.floor = mlx_xpm_file_to_image(game->mlx, I_FLOOR,
			&game->i.width, &game->i.height);
	game->i.exit1 = mlx_xpm_file_to_image(game->mlx, I_EXIT1,
			&game->i.width, &game->i.height);
	game->i.exit2 = mlx_xpm_file_to_image(game->mlx, I_EXIT2,
			&game->i.width, &game->i.height);
	game->i.exit3 = mlx_xpm_file_to_image(game->mlx, I_EXIT3,
			&game->i.width, &game->i.height);
	game->i.exit4 = mlx_xpm_file_to_image(game->mlx, I_EXIT4,
			&game->i.width, &game->i.height);
	game->i.mob = mlx_xpm_file_to_image(game->mlx, I_MOB,
			&game->i.width, &game->i.height);
	game->i.mobl = mlx_xpm_file_to_image(game->mlx, I_MOBL,
			&game->i.width, &game->i.height);
}

void	choose_img(t_game *game)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.wall, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.floor, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.player, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.collect, game->x * 64, game->y * 64);
	else if (game->map[game->y][game->x] == 'M')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.mob, game->x * 64, game->y * 64);
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

int	anima(t_game *game)
{
	static int	i;

	i++;
	if (i == 100)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit1, game->ex * 64, game->ey * 64);
	if (i == 5000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit2, game->ex * 64, game->ey * 64);
	if (i == 9000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit3, game->ex * 64, game->ey * 64);
	if (i == 12000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit4, game->ex * 64, game->ey * 64);
	if (i == 15000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit3, game->ex * 64, game->ey * 64);
	if (i == 17000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit4, game->ex * 64, game->ey * 64);
	if (i == 20000)
		i = 4999;
	return (0);
}
