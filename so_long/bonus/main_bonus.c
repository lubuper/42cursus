/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/09 12:26:25 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nWrong input!\n", 2);
		exit(1);
	}
	initialize(&game);
	check_mapfile(av);
	hold_map_m(&game, av);
	final_checks(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 64 * game.cols, (64 * game.lines) + 25,
			"so_long");
	load_i(&game);
	put_image(&game);
	mlx_key_hook(game.win, key_map, &game);
	mlx_hook(game.win, 17, M_CLICK_X, close_win, &game);
	mlx_loop_hook(game.mlx, anima, &game);
	mlx_loop(game.mlx);
}
