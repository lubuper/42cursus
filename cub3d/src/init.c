/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:42:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 20:26:39 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	mlx_initiate(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "cub3D");
	d->i.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->i.addr = mlx_get_data_addr(d->i.img, &d->i.bpp, &d->i.line_len,
			&d->i.endian);
	mlx_hook(d->win, 02, 1L << 0, keypress, d);
	mlx_hook(d->win, 03, 1L << 1, keyrelease, d);
	mlx_hook(d->win, 17, M_CLICK_X, close_win, d);
	if (!load_imgs(d))
	{
		printf("Error\nCouldn't load images\n");
		frees(d);
		exit(1);
	}
	mlx_img_init(d);
}

void	init_struct(t_data	*d, int ac, char **av)
{
	ft_memset(d, 0, sizeof(*d));
	valid_file(ac, av);
	handle_file(d, av);
	treat_map(d);
	dir_angle(d);
	verify_values(d);
	if (!d->d)
	{
		printf("Error\nInvalid player direction!\n");
		frees(d);
	}
}

void	mlx_img_init(t_data *d)
{
	d->swtex.addr = mlx_get_data_addr(d->swtex.img, &d->swtex.bpp,
			&d->swtex.line_len, &d->swtex.endian);
	d->nwtex.addr = mlx_get_data_addr(d->nwtex.img, &d->nwtex.bpp,
			&d->nwtex.line_len, &d->nwtex.endian);
	d->ewtex.addr = mlx_get_data_addr(d->ewtex.img, &d->ewtex.bpp,
			&d->ewtex.line_len, &d->ewtex.endian);
	d->wwtex.addr = mlx_get_data_addr(d->wwtex.img, &d->wwtex.bpp,
			&d->wwtex.line_len, &d->wwtex.endian);
}

void	map_for_dda(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d->lns)
	{
		x = 0;
		d->dmap[y] = onelloc(1, d->cols);
		while (d->map[y][x] && d->map[y][x] != ' ')
		{
			d->dmap[y][x] = d->map[y][x];
			x++;
		}
		y++;
	}
	x = 0;
	while (x < d->lns && d->lns > 0)
	{
		if (d->map[x])
			free(d->map[x]);
		x++;
	}
	free(d->map);
	d->map = d->dmap;
}
