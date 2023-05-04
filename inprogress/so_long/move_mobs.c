/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:43:59 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 11:31:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	mob_v(t_game *game)
{
	if (game->flag == 1)
		game->my += 1;
	else if (game->flag == 2)
		game->my -= 1;
	else if (game->flag == 3)
		game->mx += 1;
	else if (game->flag == 4)
		game->mx -= 1;
	return ;
}

void	mob_up(t_game *game)
{
	game->my -= 1;
	game->flag = 1;
	if (game->map[game->my][game->mx] == '1' ||
		game->map[game->my][game->mx] == 'E' ||
			game->map[game->my][game->mx] == 'C')
		mob_v(game);
		moving_walls(game);
	else
	{
		game->map[game->my][game->mx] = 'M';
		game->map[game->my + 1][game->mx] = '0';
	}
}

void	lets_move(t_game *game)
{
	int	dir;
	
	dir = rand () % 4;
	if (dir == 1)
	{	
		;
	}
	else if (dir == 2)
	{
	 	;
	}
	else if (dir == 3)
	{
		;
	}
	else if (dir == 4)
	{
		;
	}

}

int     is_mob(t_game *game)
{
	game->y = 0;
	while (game->y < game->lines)
	{
		game->x = 0;
		while (game->x < game->cols)
		{
			if (game->map[game->y][game->x] == 'M')
				lets_move(game);
			game->x++;
		}
		game->y++;
	}
	return (count);
}
