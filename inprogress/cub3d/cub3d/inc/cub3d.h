/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:39:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 19:07:25 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// libraries
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

// structure definitions

typedef struct	s_img
{
	char	*nwall;
	char	*swall;
	char	*wwall;
	char	*ewall;
	char	*addr;
	char	*floor_c;
	char	*ceil_c;
	int		line_len;
	int		bitspp;
	int		ceiling_colour;
	int		floor_colour;
	int		f_r;
	int		f_g;
	int		f_b;
	int 	fc_flag;
}				t_img;

 typedef struct	s_flag
{
	int		f;
	int		c;
	int		ea;
	int		we;
	int		so;
	int		no;
}				t_flag;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	i;
	char	**file;
	char	**map;
	char	**mapdup;
	int		lines;
	int		current_line;
	int		cols;
	int		x;
	int		y;
	float	px;
	float	py;
	char	d;
	int		flag_six;
	int		angle;
	bool	flag_pos;
	int		end_flag;
	t_flag	flag;
}				t_data;


// functions -by file (to organize at the end)

// draw.c
int		draw_table(t_data *d);
void	put_grid(t_data *d);

// file_val.c
void	valid_file(int ac, char **av);
void	check_mapfile(char **av);

// ft_angle.c
int		ft_angle(int nbr);
void	dir_angle(t_data *d);

// init.c
void	init_struct(t_data	*d, int ac, char **av);

// line_val.cceiling_colour
void	color_to_var(t_data *d, char *line);
void	path_to_var(t_data *d, char *line);
void	check_info_path(t_data *d, char *path);
void	deny_struct_n(char *str);

// main.c
int	main(int ac, char **av);

// map_val1.c
int		valid_first_walls(t_data *d);
int		valid_remain_walls(t_data *d);
void	treat_map(t_data *d);
int		verify_conditions(t_data *d);

// map_val2.c
int		gnllen(int fd);

// read_file.c
int 	count_lines(char **av);//conta as linhas do ficheiro 
void	handle_file(t_data *d, char **av);
void	treat_line(t_data *d, char *line);
void	verify_line_data(t_data *d, char *line);
void	verify_map_line(t_data *d, char *line);

// utils.c
int		key_map(int keycode, t_data *d);
int		close_win(t_data *d);
void	frees(t_data *d);
void	pixel_to_scr(t_data *d, int x, int y, int color);
void	free_imgs(t_data *d);
char	*ft_specialdup(char *str);

//color_utils.c
int		rgb_to_int(int red, int green, int blue);
int		max_min(t_data *d, char *nbr);
int		inspect_line(t_data *d, char *line);
void	verify_values(t_data *d);
void	draw_floor_ceil(t_data *d);

// key definitions
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP_A 65262
# define LEFT_A 65261
# define DOWN_A 65264
# define RIGHT_A 65263
# define M_CLICK_X 21275296
# define ENTER 65293


# define WIDTH 1280
# define HEIGHT 720

#endif