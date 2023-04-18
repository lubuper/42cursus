/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/17 17:12:18 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_g(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		//free (ga.map);
		exit (0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_img	img;
	char	*relative_path = "./imgs/block.xpm";
	char	*relative_path_two = "./imgs/Idle2.xpm";
	int	img_width;
	int	img_height;

	if (ac > 2)
	{
		ft_printf("Error: wrong input\n");
		exit(1);
	}
	else
	{
		check_mapfile(av);
		game.x = 100;
		game.y = 84;
		hold_map_m(game, av);
		game.colour = 0xccf1ff;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 1024, 768, "so_long");
		mlx_hook(game.win, 2, 1L<<0, close_g, &game);
		img.wall = mlx_xpm_file_to_image(game.mlx, relative_path, &img_width, &img_height);
		img.player = mlx_xpm_file_to_image(game.mlx, relative_path_two, &img_width, &img_height);
		game.addr = mlx_get_data_addr(img.wall, &game.bits_per_pixel, &game.line_length,
			&game.endian);
		game.addr = mlx_get_data_addr(img.player, &game.bits_per_pixel, &game.line_length,
			&game.endian);
		mlx_put_image_to_window(game.mlx, game.win, img.wall, 0, 0);
		mlx_put_image_to_window(game.mlx, game.win, img.player, 50, 0);
		mlx_loop(game.mlx);
	}
}
