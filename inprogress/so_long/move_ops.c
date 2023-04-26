/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:05:45 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/26 21:05:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	check_ppos(t_game *game)
{
	if (game->map[game->py][game->px] == '1')
		ft_printf("ola");
}
*/
void	move_up(t_game *game, t_img *img)
{
	game->py -= 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->py += 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, (game->py + 1) * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_down(t_game *game, t_img *img)
{
	game->py += 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->py -= 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, game->px * 16, (game->py - 1) * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_left(t_game *game, t_img *img)
{
	game->px -= 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->px += 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, (game->px + 1) * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}

void	move_right(t_game *game, t_img *img)
{
	game->px += 1;
	if (game->map[game->py][game->px] == '1')
	{
		game->px -= 1;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		img->floor, (game->px - 1) * 16, game->py * 16);
	mlx_put_image_to_window(game->mlx, game->win,
		img->player, game->px * 16, game->py * 16);
	game->moves++;
	ft_printf("Move count = %d\n", game->moves);
}
