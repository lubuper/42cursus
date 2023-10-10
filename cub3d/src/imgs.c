/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:59:02 by lubu              #+#    #+#             */
/*   Updated: 2023/09/28 14:33:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	verify_img_path(t_data *d)
{
	int	fd[4];

	fd[0] = open(d->c.nwall, O_RDONLY);
	fd[1] = open(d->c.swall, O_RDONLY);
	fd[2] = open(d->c.wwall, O_RDONLY);
	fd[3] = open(d->c.ewall, O_RDONLY);
	if (close(fd[0]) == -1 || close(fd[1]) == -1 || close(fd[2]) == -1
		|| close(fd[3]) == -1)
	{
		printf("Error\nInvalid path: %s\n", d->c.ewall);
		frees(d);
		exit(1);
	}
}

void	pixel_to_scr(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->i.addr + (y * d->i.line_len + x * (d->i.bpp / 8));
	*(unsigned int *)dst = color;
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
	if (d->nwtex.img == NULL || d->ewtex.img == NULL || d->wwtex.img == NULL
		|| d->swtex.img == NULL)
		return (0);
	return (1);
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
