/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:42:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 18:01:32 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	mlx_initiate(t_data *d)
{
	d->kflag.speed = 3;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "cub3D");
	d->i.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->i.addr = mlx_get_data_addr(d->i.img, &d->i.bpp, &d->i.line_len,
			&d->i.endian);
	draw_floor_ceil(d);
	d->mm.img = mlx_new_image(d->mlx, MMH, MMW);
	d->mm.addr = mlx_get_data_addr(d->mm.img, &d->mm.bpp, &d->mm.line_len,
			&d->mm.endian);
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
	mlx_mouse_move(d->mlx, d->win, 0, 0);
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
	d->c.hud1 = "./textures/1hud.xpm";
	d->c.hud2 = "./textures/2hud.xpm";
	d->c.hud3 = "./textures/3hud.xpm";
	d->c.wi = "./textures/wi.xpm";
	d->c.w2 = "./textures/w2.xpm";
	d->c.w3 = "./textures/w3.xpm";
	d->c.ptl = "./textures/PTL.xpm";
	d->c.door = "./textures/DOOR.xpm";
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
	d->hud1.addr = mlx_get_data_addr(d->hud1.img, &d->hud1.bpp,
			&d->hud1.line_len, &d->hud1.endian);
	d->hud2.addr = mlx_get_data_addr(d->hud2.img, &d->hud2.bpp,
			&d->hud2.line_len, &d->hud2.endian);
	d->hud3.addr = mlx_get_data_addr(d->hud3.img, &d->hud3.bpp,
			&d->hud3.line_len, &d->hud3.endian);
	d->wi.addr = mlx_get_data_addr(d->wi.img, &d->wi.bpp,
			&d->wi.line_len, &d->wi.endian);
	d->w2.addr = mlx_get_data_addr(d->w2.img, &d->w2.bpp,
			&d->w2.line_len, &d->w2.endian);
	d->w3.addr = mlx_get_data_addr(d->w3.img, &d->w3.bpp,
			&d->w3.line_len, &d->w3.endian);
	d->ptl.addr = mlx_get_data_addr(d->ptl.img, &d->ptl.bpp,
			&d->ptl.line_len, &d->ptl.endian);
	d->door.addr = mlx_get_data_addr(d->door.img, &d->door.bpp,
			&d->door.line_len, &d->door.endian);
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
		while (d->map[y][x])
		{
			if (d->map[y][x] != ' ')
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
