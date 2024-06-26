/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:45:29 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 23:45:21 by lde-sous         ###   ########.fr       */
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
	if (temp == 0)
		return (0);
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

	game->y = 0;
	while (1)
	{
		temp = get_next_line(fd, true);
		if (!temp)
		{
			free (temp);
			break ;
		}
		game->map[game->y] = temp;
		game->mapd[game->y] = ft_strdup(temp);
		game->y++;
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

void	init_imgs(t_game *game)
{
	game->i.width = 64;
	game->i.height = 64;
	game->i.player = 0;
	game->i.playerl = 0;
	game->i.playerr = 0;
	game->i.floor = 0;
	game->i.wall = 0;
	game->i.exit = 0;
	game->i.collect = 0;
}
