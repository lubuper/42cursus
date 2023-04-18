/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:20:43 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/18 20:25:55 by lde-sous         ###   ########.fr       */
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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_game;

typedef struct s_img
{
	int	width;
	int	height;
	void	*player;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collect;
}			t_img;

int		key_map(int keycode, t_game *game);
int		check_mapfile(char **av);
void	free_the_code(t_game *game);	
void	valid_shape(t_game *game);
void	valid_walls(t_game *game);
void	hold_map_m(t_game *game, char **av);
void	put_image(t_game *game, t_img *img);
void	load_img(t_game *game, t_img *img);

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100

#endif
