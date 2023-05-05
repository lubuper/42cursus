/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:20:43 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/04 22:11:11 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

typedef struct s_i
{
	int		width;
	int		height;
	void	*player;
	void	*playerl;
	void	*playerr;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*collect;
}			t_i;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*addr;
	char	**map;
	char	**mapd;
	t_i		i;
	int		cs;
	int		lines;
	int		cols;
	int		x;
	int		y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		py;
	int		px;
	int		moves;
	int		flag;
}			t_game;

int		key_map(int keycode, t_game *game);
int		ecount(t_game *game, char c);
int		check_mapfile(char **av);
int		close_win(t_game *game);
int		gnllen(int fd);
int		gnllines(int fd);
int		valid_path(t_game *game, char **map, int y, int x);
void	initialize(t_game *game);
void	init_imgs(t_game *game);
void	startpos(t_game *game);
void	hold_map_m(t_game *game, char **av);
void	gnlfreed(t_game *game, int fd);
void	negate_n(t_game *game);
void	valid_shape(t_game *game);
void	valid_walls(t_game *game);
void	check_map(t_game *game);
void	final_checks(t_game *game);
void	load_i(t_game *game);
void	put_image(t_game *game);
void	put_image_l(t_game *game);
void	put_image_r(t_game *game);
void	choose_img(t_game *game);
void	choose_img_l(t_game *game);
void	choose_img_r(t_game *game);
void	moving_checks(t_game *game);
void	moving_walls(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	free_the_code(t_game *game);
void	destroy_imgs(t_game *game);

# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define M_CLICK_X 21275296
# define I_WALL "./textures/wall.xpm"
# define I_PLAYER "./textures/player.xpm"
# define I_PLAYERL "./textures/playerl.xpm"
# define I_PLAYERR "./textures/playerr.xpm"
# define I_COLLECT "./textures/collect.xpm"
# define I_FLOOR "./textures/floor.xpm"
# define I_EXIT "./textures/exit.xpm"

#endif
