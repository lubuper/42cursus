/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/08 14:59:54 by lde-sous         ###   ########.fr       */
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
	game->i.exit = mlx_xpm_file_to_image(game->mlx, I_EXIT,
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
	else if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->i.exit, game->x * 64, game->y * 64);
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
	int		lim;
	
	lim = 18000;
		i++;
		if (i == lim)
			mlx_put_image_to_window(game->mlx, game->win,
				game->i.exit1, game->x * 32, game->y * 32);
		if (i == lim * 2)
			mlx_put_image_to_window(game->mlx, game->win,
				game->i.exit2, game->x * 32, game->y * 32);
		if (i == lim * 3)
			mlx_put_image_to_window(game->mlx, game->win,
				game->i.exit3, game->x * 32, game->y * 32);
		if (i == lim * 4)
			mlx_put_image_to_window(game->mlx, game->win,
				game->i.exit4, game->x * 32, game->y * 32);
	return (0);
}
