/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:39:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 19:34:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

typedef struct s_proj
{
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;
	float	angle;
	float	speed;
	float	len_v;
	float	len_h;
	float	stepx;
	float	stepy;
	int		mcx;
	int		mcy;
	int		dist;
	float	v_x;
	float	v_y;
	float	h_x;
	float	h_y;
}				t_proj;

typedef struct s_rays
{
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
	char	*door;
	char	*hud1;
	char	*hud2;
	char	*hud3;
	char	*floor_c;
	char	*ceil_c;
	char	*wi;
	char	*w2;
	char	*w3;
	char	*ptl;
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
	bool	shift;
	bool	open;
	int		speed;
	bool	fire;
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
	t_img		door;
	t_img		hud1;
	t_img		hud2;
	t_img		hud3;
	t_img		wi;
	t_img		w2;
	t_img		w3;
	t_img		ptl;
	t_img		mm;
	t_color		c;
	t_rays		r;
	t_proj		plasma;
	t_flag		flag;
	t_keyflag	kflag;
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
	int			counter;
	int			mousex;
	int			mousey;
	int			flag_six;
	bool		flag_pos;
	bool		end_flag;
	float		fow;
	int			setx;
	int			sety;
}				t_data;

// functions -by file

// animation.c
void			door_action(t_data *d);
void			check_door_loc(t_data *d, int *x, int *y);
void			shoot(t_data *d);
void			projectile_draw(t_data *d, int x1, int y1);
void			gun_animation(t_data *d);

// color_utils_bonus.c
int				rgb_to_int(int red, int green, int blue);
int				max_min(t_data *d, char *nbr);
int				inspect_line(t_data *d, char *line);
void			verify_values(t_data *d);
void			draw_floor_ceil(t_data *d);

// draw_bonus.c
void			draw_walls(t_data *d);
t_img			get_image(t_data *d, char wall);
void			draw_vline(t_data *d, int x, char wall);
int				get_tex_x(t_data *d, char wall);
int				shadecolor(t_data *d, int color, float shader);

// draw_border.c
void			draw_border_top(t_data *d);
void			draw_border_left(t_data *d);
void			draw_border_right(t_data *d);
void			draw_border_bottom(t_data *d);
void			draw_border(t_data *d);

// draw_map_bonus.c
void			pixel_to_map(t_data *d, int x, int y, int color);
void			draw_square(t_data *d, int x, int y, int color);
void			bg_map(t_data *d);
int				player_distx(t_data *d);
int				player_disty(t_data *d);

// draw_map_bonus2.c
void			draw_player_map(t_data *d, int color);
void			draw_map(t_data *d);

// file_val_bonus.c
void			valid_file(int ac, char **av);
void			check_mapfile(char **av);
void			pixel_to_scr(t_data *d, int x, int y, int color);
int				colornbr(char *str);

// frees_bonus.c
int				close_win(t_data *d);
void			frees(t_data *d);
void			free_imgs(t_data *d);
void			free_imgs2(t_data *d);
void			handle_file_aux(t_data *d);

// ft_angle_bonus.c
float			ft_angle(int nbr);
void			dir_angle(t_data *d);
void			mouse_move(t_data *d);
void			mouse_x(t_data *d, int *off_x);
void			mouse_y(t_data *d, int *off_y);

// imgs_bonus.c
void			verify_img_path(t_data *d);
int				load_imgs(t_data *d);
void			load_imgs_aux(t_data *d);
unsigned int	get_colors(t_img *img, int x, int y);
void			put_hud(t_data *d, int i);

// init_bonus.c
void			mlx_initiate(t_data *d);
void			init_struct(t_data	*d, int ac, char **av);
void			mlx_img_init(t_data *d);
void			map_for_dda(t_data *d);

// line_val_bonus.c
void			color_to_var(t_data *d, char *line);
void			path_to_var(t_data *d, char *line);
void			check_info_path(t_data *d, char *path);
void			deny_struct_n(char *str);
int				colornbr(char *str);

// main_bonus.c
int				game_loop(t_data *d);
int				main(int ac, char **av);

// map_val1_bonus.c
int				valid_first_walls(t_data *d);
int				valid_remain_walls(t_data *d);
void			treat_map(t_data *d);
int				verify_conditions(t_data *d);
void			fill_map_for_dda(t_data *d);

// move_bonus.c
void			move_player(t_data *d);
void			w_move(t_data *d);
void			w_bob(t_data *d, t_img img, int x1, int y1);

// move_bonus2.c
int				pvtocollision(t_data *d);
void			move_forward(t_data *d);
void			move_backwards(t_data *d);
void			strafe_left(t_data *d, float right_angle);
void			strafe_right(t_data *d, float right_angle);

// move_bonus2.c
void			look(t_data *d);

// raycast_bonus.c
char			determine_wall(t_data *d);
void			dda_draw(t_data *d, int x);
void			calc_angle(t_data *d, float ca);
void			wall_check_h(t_data *d, bool is_wall);
void			calc_inter_h(t_data *d);

// raycast2_bonus.c
void			wall_check_v(t_data *d, bool is_wall);
void			calc_inter_v(t_data *d);

// rc_projectile.c
void			check_horizontal_hit(t_data *d);
void			check_horizontal_gridline(t_data *d, bool is_wall);
void			check_vertical_hit(t_data *d);
void			check_vertical_gridline(t_data *d, bool is_wall);
void			dda_projectile(t_data *d);

// read_file_bonus.c
int				count_lines(char **av);
void			handle_file(t_data *d, char **av);
void			treat_line(t_data *d, char *line, char *line2);
void			verify_line_data(t_data *d, char *line, char *line2);
void			verify_map_line(t_data *d, char *l);

// utils_bonus.c
int				keyrelease(int keycode, t_data *d);
int				keypress(int keycode, t_data *d);
char			*ft_specialdup(char *str);
void			*onelloc(size_t nmemb, size_t size);
void			iv_line_err(t_data *d, char *line, char *line2);

// key definitions
# define ESC 65307
# define SHIFT 65505
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define UP_A 65362
# define LEFT_A 65361
# define DOWN_A 65364
# define RIGHT_A 65363
# define M_CLICK_X 21275296
# define ENTER 65293
# define PI 3.14159265
# define DR 0.01745329
# define TS 64
# define TSM 16
# define WIDTH 1280
# define HEIGHT 720
# define MMW 170
# define MMH 170
# define PV 2
# define PVM 0.1
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00

#endif
