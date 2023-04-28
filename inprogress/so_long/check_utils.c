/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:45:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/28 21:40:07 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ecount(t_game *game, char c)
{
	int	count;

	count = 0;
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == c)
				count++;
			game->x++;
		}
			game->y++;
	}
	return (count);
}

void	check_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->lines)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!(game->map[y][x] == '1' || game->map[y][x] == '0'
				|| game->map[y][x] == 'P' || game->map[y][x] == 'C'
					|| game->map[y][x] == 'E'))
			{
				ft_printf("Error: invalid map element\n");
				free_the_code(game);
			}
			x++;
		}
			y++;
	}
	if (ecount(game, 'P') > 1 || ecount(game, 'E') > 1 || ecount(game, 'C') < 1)
	{
		ft_printf("Error: invalid number of map elements");
		free_the_code(game);
	}
}
