/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/04 14:41:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	game_loop(t_data *d)
{
	static int	i;

	mouse_move(d);
	move_player(d);
	door_action(d);
	draw_floor_ceil(d);
	d->pdx = cos(d->pa);
	d->pdy = sin(d->pa);
	draw_walls(d);
	draw_map(d);
	draw_border(d);
	if (d->kflag.fire == 1)
		shoot(d);
	mlx_clear_window(d->mlx, d->win);
	mlx_put_image_to_window(d->mlx, d->win, d->i.img, 0, 0);
	mlx_put_image_to_window(d->mlx, d->win, d->mm.img, 10, 10);
	put_hud(d, i);
	i++;
	if (i == 100)
		i = 0;
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
