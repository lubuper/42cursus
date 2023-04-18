/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 20:26:10 by lde-sous         ###   ########.fr       */
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
	else
	{
		check_mapfile(av);
		hold_map_m(&game, av);
		free_the_code(&game);
		load_img(&game, &img);
		put_image(&game, &img);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 1024, 768, "so_long");
		mlx_key_hook(game.win, key_map, &game);
		mlx_hook(game.win, 4, 1L<<2, key_map, &game);
		mlx_loop(game.mlx);
	}
}
