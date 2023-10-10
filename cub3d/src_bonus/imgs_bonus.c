/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:59:02 by lubu              #+#    #+#             */
/*   Updated: 2023/10/09 17:09:05 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	verify_img_path(t_data *d)
{
	int	fd[11];

	fd[0] = open(d->c.nwall, O_RDONLY);
	fd[1] = open(d->c.swall, O_RDONLY);
	fd[2] = open(d->c.wwall, O_RDONLY);
	fd[3] = open(d->c.ewall, O_RDONLY);
	fd[4] = open(d->c.hud1, O_RDONLY);
	fd[5] = open(d->c.hud2, O_RDONLY);
	fd[6] = open(d->c.hud3, O_RDONLY);
	fd[7] = open(d->c.door, O_RDONLY);
	fd[8] = open(d->c.wi, O_RDONLY);
	fd[9] = open(d->c.w2, O_RDONLY);
	fd[10] = open(d->c.w3, O_RDONLY);
	if (close(fd[0]) == -1 || close(fd[1]) == -1 || close(fd[2]) == -1
		|| close(fd[3]) == -1 || close(fd[4]) == -1 || close(fd[5]) == -1
		|| close(fd[6]) == -1 || close(fd[7]) == -1 || close(fd[8]) == -1
		|| close(fd[9]) == -1 || close(fd[10]) == -1)
	{
		printf("Error\nInvalid path: no .xpm texture\n");
		frees(d);
		exit(1);
	}
}

int	load_imgs(t_data *d)
{
	d->nwtex.img = mlx_xpm_file_to_image(d->mlx, d->c.nwall, &d->nwtex.width,
			&d->nwtex.height);
	d->ewtex.img = mlx_xpm_file_to_image(d->mlx, d->c.ewall, &d->ewtex.width,
			&d->ewtex.height);
	d->wwtex.img = mlx_xpm_file_to_image(d->mlx, d->c.wwall, &d->wwtex.width,
			&d->wwtex.height);
	d->swtex.img = mlx_xpm_file_to_image(d->mlx, d->c.swall, &d->swtex.width,
			&d->swtex.height);
	d->door.img = mlx_xpm_file_to_image(d->mlx, d->c.door, &d->door.width,
			&d->door.height);
	d->hud1.img = mlx_xpm_file_to_image(d->mlx, d->c.hud1, &d->hud1.width,
			&d->hud1.height);
	d->hud2.img = mlx_xpm_file_to_image(d->mlx, d->c.hud2, &d->hud2.width,
			&d->hud2.height);
	d->hud3.img = mlx_xpm_file_to_image(d->mlx, d->c.hud3, &d->hud3.width,
			&d->hud3.height);
	load_imgs_aux(d);
	if ((!d->nwtex.img || !d->ewtex.img || !d->wwtex.img || !d->swtex.img
			|| !d->hud1.img || !d->hud2.img || !d->hud3.img || !d->wi.img
			|| !d->ptl.img || !d->w2.img || !d->w3.img))
		return (0);
	return (1);
}

void	load_imgs_aux(t_data *d)
{
	d->wi.img = mlx_xpm_file_to_image(d->mlx, d->c.wi, &d->wi.width,
			&d->wi.height);
	d->w2.img = mlx_xpm_file_to_image(d->mlx, d->c.w2, &d->w2.width,
			&d->w2.height);
	d->w3.img = mlx_xpm_file_to_image(d->mlx, d->c.w3, &d->w3.width,
			&d->w3.height);
	d->ptl.img = mlx_xpm_file_to_image(d->mlx, d->c.ptl, &d->ptl.width,
			&d->ptl.height);
}

unsigned int	get_colors(t_img *img, int x, int y)
{
	unsigned int	result;

	if (y > 0)
		result = *(unsigned int *)((img->addr + (y * img->line_len) + \
		x * (img->bpp / 8)));
	else
		return (0);
	return (result);
}

void	put_hud(t_data *d, int i)
{
	if (d->counter >= 0)
		w_move(d);
	if (i >= 0 && i < 21)
		mlx_put_image_to_window(d->mlx, d->win, d->hud2.img,
			(WIDTH / 2) - 220, HEIGHT - 61);
	else if (i > 20 && i < 41)
		mlx_put_image_to_window(d->mlx, d->win, d->hud1.img,
			(WIDTH / 2) - 220, HEIGHT - 61);
	else if (i >= 40 && i < 81)
		mlx_put_image_to_window(d->mlx, d->win, d->hud2.img,
			(WIDTH / 2) - 220, HEIGHT - 61);
	else if (i > 80)
		mlx_put_image_to_window(d->mlx, d->win, d->hud3.img,
			(WIDTH / 2) - 220, HEIGHT - 61);
}
