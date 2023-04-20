/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:36:07 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 21:06:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_game *game, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->lines)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!(game->map[y][x] == '1' || game->map[y][x] == '0'
						|| game->map[y][x] == 'P' || game->map[y][x] == 'C'
						|| game->map[y][x] == 'E'))
			{
				ft_printf("Error: invalid map element\n");
				free_the_code(game, img);
			}
			x++;
		}
		y++;
	}
}

void	load_img(t_game *game, t_img *img)
{
	img->wall = mlx_xpm_file_to_image(game->mlx, IMG_WALL,
			&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(game->mlx, IMG_PLAYER,
			&img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(game->mlx, IMG_COLLECT,
			&img->width, &img->height);
	img->floor = mlx_xpm_file_to_image(game->mlx, IMG_FLOOR,
			&img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(game->mlx, IMG_EXIT,
			&img->width, &img->height);
/*	game->addr = mlx_get_data_addr(img->wall, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	game->addr = mlx_get_data_addr(img->player, &game->bits_per_pixel,
			&game->line_length, &game->endian);*/
}

void	put_image(t_game *game, t_img *img)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					img->wall, (game->x * 16), (game->y * 16));
			else if (game->map[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					img->floor, (game->x * 16), (game->y * 16));
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					img->player, (game->x * 16), (game->y * 16));
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					img->collect, (game->x * 16), (game->y * 16));
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					img->exit, (game->x * 16), (game->y * 16));
			game->x++;
		}
		game->y++;
	}
}

/*void	player_move(t_game *game, t_img *img)
{
	if (
}

*/
