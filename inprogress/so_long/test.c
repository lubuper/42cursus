/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 21:04:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	t_img	img;

	if (ac > 2)
	{
		ft_printf("Error: wrong input\n");
		exit(1);
	}
	initialize(&game, &img);
	check_mapfile(av);
	hold_map_m(&game, &img, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 16 * game.cols, 16 * (game.lines), "so_long");
	mlx_key_hook(game.win, key_map, &game);
	mlx_hook(game.win, 17, M_CLICK_X, close_win, &game);
	load_img(&game, &img);
	put_image(&game, &img);
	mlx_loop(game.mlx);
}
