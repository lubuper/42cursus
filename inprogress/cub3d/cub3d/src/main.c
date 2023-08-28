/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:20:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 16:14:14 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	printmap(t_data *d)
{
	int x;
	int y;

	y = 0;
	while (y < d->lines)
	{
		x = 0;
		while (x < (int)ft_strlen(d->map[y]))
		{
			printf("%c", d->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}

}

int	main(int ac, char **av)
{
	t_data	d;

	init_struct(&d, ac, av);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "cub3D");
	mlx_key_hook(d.win, key_map, &d);
	mlx_hook(d.win, 17, M_CLICK_X, close_win, &d);
	mlx_loop_hook(d.mlx, draw_table, &d);
	mlx_loop(d.mlx);
	return (0);
}
