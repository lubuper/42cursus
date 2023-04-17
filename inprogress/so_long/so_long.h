/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:20:43 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/17 20:29:15 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	**map;
	int		lines;
	int		cols;
	int		x;
	int		y;
	int		colour;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_game;

typedef struct s_img
{
	void	*player;
	void	*floor;
	void	*wall;
	void	*enemy;
	void	*collectable;
}			t_img;

int		check_mapfile(char **av);
void	valid_shape(t_game game);
void	valid_walls(t_game game);
void	hold_map_m(t_game game, char **av);
void	put_image(t_game game);

#endif