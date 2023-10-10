/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_val_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:04:08 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 20:11:45 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	color_to_var(t_data *d, char *line)
{
	int		i;

	i = 0;
	if (!ft_isprint(line[i]) || line[i] == ' ')
		d->end_flag = true;
	if (!ft_strncmp(&line[i], "F ", 2))
	{
		d->c.floor_c = ft_strdup(&line[i + 2]);
		deny_struct_n(d->c.floor_c);
		d->flag.f = true;
	}
	else if (!ft_strncmp(&line[i], "C ", 2))
	{
		d->c.ceil_c = ft_strdup(&line[i + 2]);
		deny_struct_n(d->c.ceil_c);
		d->flag.c = true;
	}
}

void	path_to_var(t_data *d, char *line)
{
	if (!ft_strncmp(&line[0], "EA ", 3))
	{
		d->c.ewall = ft_strdup(&line[3]);
		deny_struct_n(d->c.ewall);
		d->flag.ea = true;
	}
	else if (!ft_strncmp(&line[0], "WE ", 3))
	{
		d->c.wwall = ft_strdup(&line[3]);
		deny_struct_n(d->c.wwall);
		d->flag.we = true;
	}
	else if (!ft_strncmp(&line[0], "SO ", 3))
	{
		d->c.swall = ft_strdup(&line[3]);
		deny_struct_n(d->c.swall);
		d->flag.so = true;
	}
	else if (!ft_strncmp(&line[0], "NO ", 3))
	{
		d->c.nwall = ft_strdup(&line[3]);
		deny_struct_n(d->c.nwall);
		d->flag.no = true;
	}
	check_info_path(d, &line[3]);
}

void	check_info_path(t_data *d, char *path)
{
	int	sufixp;
	int	beg;

	sufixp = ft_strlen(path) - 5;
	beg = 2;
	if (ft_strncmp(&path[0], "./", 2) || ft_strncmp(&path[sufixp], ".xpm\n", 5))
		d->end_flag = true;
	while (beg < sufixp)
	{
		if (!ft_isprint(path[beg]) || path[beg] == ' ')
			d->end_flag = true;
		beg++;
	}
}

void	deny_struct_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = 0;
		i++;
	}
}

int	colornbr(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i] != '\n')
	{
		if (str[i] == ',')
		{
			flag++;
			if (flag == 1 && str[i - 1] == ' ')
				return (0);
			else if (flag == 2 && str[i + 1] && str[i + 1] == '\n')
				return (0);
		}
		i++;
	}
	if (flag == 1)
		return (0);
	return (1);
}
