/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:11:35 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/10 20:47:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}			t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g(in
t trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/*
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;
	int	colour;
	int	i;

	x = 100;
	y = 184;
	i = 2;
	colour = 0xccf1ff;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 768, "so_long");
	img.img = mlx_new_image(mlx, 1024, 768);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	while (y <= 700)
	{
		my_mlx_pixel_put(&img, x, y, colour);
		my_mlx_pixel_put(&img, x + 30, y + 30, colour);
		y++;
		colour *= i;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/
int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	x;
	int	y;
	int	colour;
	int	i;

	x = 100;
	y = 184;
	i = 2;
	colour = 0xccf1ff;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1024, 768, "so_long");
	img.img = mlx_new_image(mlx, 1024, 768);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	while (y <= 700)
	{
		my_mlx_pixel_put(&img, x, y, colour);
		my_mlx_pixel_put(&img, x + 30, y + 30, colour);
		y++;
		colour *= i;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
