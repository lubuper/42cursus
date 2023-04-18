/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 20:05:18 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_game *game, t_img *img)
{
	char	*wall_ipath;
	char	*player_ipath;
	char	*collect_ipath;
	char	*floor_ipath;
	char	*exit_ipath;

	wall_ipath = "./imgs/wall.xpm";
	player_ipath = "./imgs/player.xpm";
	collect_ipath = "./imgs/collect.xpm";
	floor_ipath = "./imgs/floor.xpm";
	exit_ipath = "./imgs/exit.xpm";
	img->wall = mlx_xpm_file_to_image(game->mlx, wall_ipath, &img->width, &img->height);
	img->player = mlx_xpm_file_to_image(game->mlx, player_ipath, &img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(game->mlx, collect_ipath, &img->width, &img->height);
	img->floor = mlx_xpm_file_to_image(game->mlx, floor_ipath, &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(game->mlx, exit_ipath, &img->width, &img->height);
	game->addr = mlx_get_data_addr(img->wall, &game->bits_per_pixel, &game->line_length,
		&game->endian);
	game->addr = mlx_get_data_addr(img->player, &game->bits_per_pixel, &game->line_length,
		&game->endian);
}

void	put_image(t_game *game, t_img *img)
{
	game->y = 0;
	game->x = 0;
	while (game->y <= game->lines)
	{
		while (game->x < game->cols)
		{
			game->x = 0;
			if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->wall, (game->y * 16), (game->x * 16));
			else if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, img->floor, (game->y * 16), (game->x * 16));
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, img->player, (game->y * 16), (game->x * 16));
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, img->collect, (game->y * 16), (game->x * 16));
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, img->exit, (game->y * 16), (game->x * 16));
			else
			{
				ft_printf("Error: invalid map element");
				exit (1);
			}
			game->x++;
		}
		game->y++;
	}
}
