/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:39:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 19:22:44 by lde-sous         ###   ########.fr       */
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

typedef struct s_rays
{
	float	texx;
	float	texy;
	int		mapcx;
	int		mapcy;
	float	h_rayx;
	float	h_rayy;
	float	v_rayx;
	float	v_rayy;
	float	rayy;
	float	rayx;
	float	len_v;
	float	len_h;
	float	stepx;
	float	stepy;
	float	ray_d;
	float	angle;
	float	wall_h;
	bool	side;
}				t_rays;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_color
{
	char	*nwall;
	char	*swall;
	char	*wwall;
	char	*ewall;
	char	*floor_c;
	char	*ceil_c;
	int		ce_color;
	int		fl_color;
	int		f_r;
	int		f_g;
	int		f_b;
	int		fc_flag;
}				t_color;

typedef struct s_flag
{
	bool		f;
	bool		c;
	bool		ea;
	bool		we;
	bool		so;
	bool		no;
}				t_flag;

typedef struct s_keyflag
{
	bool	forward;
	bool	backwards;
	bool	strafe_r;
	bool	strafe_l;
	bool	look_r;
	bool	look_l;
}				t_keyflag;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		i;
	t_img		nwtex;
	t_img		ewtex;
	t_img		wwtex;
	t_img		swtex;
	t_color		c;
	t_rays		r;
	char		**dmap;
	char		**map;
	int			lns;
	int			current_line;
	int			cols;
	int			x;
	int			y;
	float		px;
	float		py;
	float		pa;
	float		pdx;
	float		pdy;
	char		d;
	int			flag_six;
	bool		flag_pos;
	bool		end_flag;
	t_flag		flag;
	t_keyflag	kflag;
}				t_data;

// functions -by file

//color_utils.c
int				rgb_to_int(int red, int green, int blue);
int				max_min(t_data *d, char *nbr);
int				inspect_line(t_data *d, char *line);
void			verify_values(t_data *d);
void			draw_floor_ceil(t_data *d);

// draw.c
void			draw_walls(t_data *d);
void			draw_vline(t_data *d, int x, char wall);
int				get_tex_x(t_data *d, char wall);

// file_val.c
void			valid_file(int ac, char **av);
void			check_mapfile(char **av);

// frees.c
int				close_win(t_data *d);
void			frees(t_data *d);
void			free_imgs(t_data *d);

// ft_angle.c
float			ft_angle(int nbr);
void			dir_angle(t_data *d);

// imgs.c
void			verify_img_path(t_data *d);
void			pixel_to_scr(t_data *d, int x, int y, int color);
int				load_imgs(t_data *d);

// init.c
void			mlx_initiate(t_data *d);
void			init_struct(t_data	*d, int ac, char **av);
void			mlx_img_init(t_data *d);
void			fill_map_for_dda(t_data *d);
void			map_for_dda(t_data *d);

// line_val
void			color_to_var(t_data *d, char *line);
void			path_to_var(t_data *d, char *line);
void			check_info_path(t_data *d, char *path);
void			deny_struct_n(char *str);

// main.c
int				game_loop(t_data *d);
int				main(int ac, char **av);

// map_val1.c
int				valid_first_walls(t_data *d);
int				valid_remain_walls(t_data *d);
void			treat_map(t_data *d);
int				verify_conditions(t_data *d);

// move.c
void			move_player(t_data *d);
void			move_forward(t_data *d);
void			move_backwards(t_data *d);
void			strafe_left(t_data *d, float right_angle);
void			strafe_right(t_data *d, float right_angle);

// raycast.c
char			determine_wall(t_data *d);
void			dda_draw(t_data *d, int x);
void			calc_angle(t_data *d, float ca);
void			wall_check_h(t_data *d, bool is_wall);
void			calc_inter_h(t_data *d);

// raycast2.c
void			calc_inter_v(t_data *d);
void			wall_check_v(t_data *d, bool is_wall);

// read_file.c
int				count_lines(char **av);//conta as linhas do ficheiro 
void			handle_file(t_data *d, char **av);
void			treat_line(t_data *d, char *line);
void			verify_line_data(t_data *d, char *line);
void			verify_map_line(t_data *d, char *line);

// utils.c
int				keyrelease(int keycode, t_data *d);
int				keypress(int keycode, t_data *d);
char			*ft_specialdup(char *str);
void			*onelloc(size_t nmemb, size_t size);
void			handle_file_aux(t_data *d);

// imgs.c
unsigned int	get_colors(t_img *img, int x, int y);
int				colornbr(char *str);

// key definitions
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP_A 65362
# define LEFT_A 65361
# define DOWN_A 65364
# define RIGHT_A 65363
# define M_CLICK_X 21275296
# define ENTER 65293
# define PI 3.14159265
# define DR 0.01745329
# define TS 64
# define SPEED 3
# define WIDTH 1280
# define HEIGHT 720

#endif
