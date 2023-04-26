/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/26 11:20:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, t_img *img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, (game->py - 1) * 16);
	game->py -= 1;
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_down(t_game *game, t_img *img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, (game->py - 1) * 16);
	game->py -= 1;
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_left(t_game *game, t_img *img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, (game->py - 1) * 16);
	game->py -= 1;
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_right(t_game *game, t_img *img)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, (game->py - 1) * 16);
	game->py -= 1;
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

