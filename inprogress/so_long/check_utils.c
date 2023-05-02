/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:45:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/01 15:10:18 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gnllen(int fd)
{
	char	*temp;
	int		len;

	temp = 0;
	len = 0;
	temp = get_next_line(fd, true);
	len = ft_strlen(temp);
	free (temp);
	return (len);
}

int	gnllines(int fd)
{
	int		count;
	char	*temp;

	count = 0;
	while (1)
	{
		temp = get_next_line(fd, true);
		if (!temp)
		{
			free (temp);
			break ;
		}
		count++;
		free (temp);
		temp = 0;
	}
	return (count);
}

void	gnlfreed(t_game *game, int fd)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(fd, true);
		if (!temp)
		{
			free (temp);
			break ;
		}
		game->map[game->y++] = temp;
	}
}

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
				ft_putstr_fd("Error\nInvalid map element!\n", 2);
				free_the_code(game);
			}
			x++;
		}
			y++;
	}
	if (ecount(game, 'P') != 1 || ecount(game, 'E') != 1 || ecount(game, 'C') < 1)
	{
		ft_putstr_fd("Error\nInvalid number of map elements!\n", 2);
		free_the_code(game);
	}
}
