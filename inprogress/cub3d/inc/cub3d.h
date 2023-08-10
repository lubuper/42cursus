/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:39:54 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/10 17:29:29 by lde-sous         ###   ########.fr       */
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

// structure definitions
typedef struct	s_data
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**mapdup;
	int		lines;
	int		cols;
	int		x;
	int		y;
	int		px;
	int		py;
	char	d;
	char	*NWALL;
	char	*SWALL;
	char	*WWALL;
	char	*EWALL;
}				t_data;


// functions -by file
int		check_mapfile(char **av);
void	init_struct(t_data	*data);

// key definitions
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define M_CLICK_X 21275296


#endif
