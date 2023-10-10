/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/09/20 19:52:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	game_loop(t_data *d)
{
	move_player(d);
	draw_floor_ceil(d);
	d->pdx = cos(d->pa);
	d->pdy = sin(d->pa);
	draw_walls(d);
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->i.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	d;

	init_struct(&d, ac, av);
	mlx_initiate(&d);
	mlx_loop_hook(d.mlx, game_loop, &d);
	mlx_loop(d.mlx);
	return (0);
}
