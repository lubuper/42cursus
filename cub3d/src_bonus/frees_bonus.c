/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:36:09 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 18:15:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	close_win(t_data *d)
{
	frees(d);
	return (0);
}

void	frees(t_data *d)
{
	int	i;

	i = 0;
	if (d->flag_six == 6)
	{
		while (i < d->lns && i < d->current_line && d->lns > 0)
		{
			free(d->map[i]);
			i++;
		}
	}
	free(d->map);
	free_imgs(d);
	if (d->i.img)
		mlx_destroy_image(d->mlx, d->i.img);
	if (d->mm.img)
		mlx_destroy_image(d->mlx, d->mm.img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
		mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(0);
}

void	free_imgs(t_data *d)
{
	if (d->c.floor_c)
		free(d->c.floor_c);
	if (d->c.ceil_c)
		free(d->c.ceil_c);
	if (d->c.nwall)
		free(d->c.nwall);
	if (d->c.wwall)
		free(d->c.wwall);
	if (d->c.ewall)
		free(d->c.ewall);
	if (d->c.swall)
		free(d->c.swall);
	if (d->ewtex.img)
		mlx_destroy_image(d->mlx, d->ewtex.img);
	if (d->swtex.img)
		mlx_destroy_image(d->mlx, d->swtex.img);
	if (d->wwtex.img)
		mlx_destroy_image(d->mlx, d->wwtex.img);
	if (d->nwtex.img)
		mlx_destroy_image(d->mlx, d->nwtex.img);
	free_imgs2(d);
}

void	free_imgs2(t_data *d)
{
	if (d->hud1.img)
		mlx_destroy_image(d->mlx, d->hud1.img);
	if (d->hud2.img)
		mlx_destroy_image(d->mlx, d->hud2.img);
	if (d->hud3.img)
		mlx_destroy_image(d->mlx, d->hud3.img);
	if (d->wi.img)
		mlx_destroy_image(d->mlx, d->wi.img);
	if (d->w2.img)
		mlx_destroy_image(d->mlx, d->w2.img);
	if (d->w3.img)
		mlx_destroy_image(d->mlx, d->w3.img);
	if (d->ptl.img)
		mlx_destroy_image(d->mlx, d->ptl.img);
	if (d->door.img)
		mlx_destroy_image(d->mlx, d->door.img);
}

void	handle_file_aux(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (d->lns < 3)
	{
		printf("Error\nInvalid map!\n");
		frees(d);
	}
}
