/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:41:49 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/01 20:06:53 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_path(t_game *game)
{
	char	**temp;
	int		y;
	int		x;
	int		flag;

	flag = 0;
	y = game->py;
	x = game->px;
	temp = game->map;
	temp[y][x] = '0';
	while (temp[y][x] != 'E')
	{
		if (temp[y][x] == '0')
		{
			temp[y][x] = 'V';
			if (temp[y][x + 1] == 0)
				flag++;
			if (temp[y][x - 1] == 0)
				flag++;
			if (temp[y + 1][x] == 0)
				flag++;
			if (temp[y - 1][x] == 0)
				flag++;
		}

	}
}
void	startpos(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == 'P')
			{
				game->px = game->x;
				game->py = game->y;
			}
			game->x++;
		}
			game->y++;
	}
	game->cs = ecount(game, 'C');
}

void	moving_checks(t_game *game)
{
	if (game->map[game->py][game->px] == 'C')
	{
		game->cs--;
		game->map[game->py][game->px] = '0';
	}
	else if (game->map[game->py][game->px] == 'E')
	{
		if (game->cs == 0)
		{
			ft_printf("Congratulations! Level Complete!\n");
			free_the_code(game);
		}
	}
}

void	final_checks(t_game *game)
{
	startpos(game);
}
