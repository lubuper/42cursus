/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:10:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 20:28:37 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_the_code(t_game *game)
{
	free(game->map);
	exit (1);
}

int	key_map(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		//free (ga.map);
		exit (0);
	}

/*	else if (keycode == W)
		dosomething;
	else if (keycode == S)
		dosomething;
	else if (keycode == A)
		dosomething;
	else if (keycode == D)
		dosomething;*/



	return (0);
}

