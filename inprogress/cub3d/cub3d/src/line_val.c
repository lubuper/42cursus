/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:04:08 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 13:01:08 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	color_to_var(t_data *d, char *line)
{
	int		i;

	i = 0;
	if (!ft_isprint(line[i]) || line[i] == ' ')
		d->end_flag = 1;
	if (!ft_strncmp(&line[i], "F ", 2))
	{
		d->i.floor_c = ft_strdup(&line[i + 2]);
		deny_struct_n(d->i.floor_c);
		d->flag.f = 1;
	}
	else if (!ft_strncmp(&line[i], "C ", 2))
	{
		d->i.ceil_c = ft_strdup(&line[i + 2]);
		deny_struct_n(d->i.ceil_c);
		d->flag.c = 1;
	}
}

void	path_to_var(t_data *d, char *line)
{
	if (!ft_strncmp(&line[0], "EA ", 3))
	{
		d->i.ewall = ft_strdup(&line[3]);
		deny_struct_n(d->i.ewall);
		d->flag.ea = 1;
	}
	else if (!ft_strncmp(&line[0], "WE ", 3))
	{
		d->i.wwall = ft_strdup(&line[3]);
		deny_struct_n(d->i.wwall);
		d->flag.we = 1;
	}
	else if (!ft_strncmp(&line[0], "SO ", 3))
	{
		d->i.swall = ft_strdup(&line[3]);
		deny_struct_n(d->i.swall);
		d->flag.so = 1;
	}
	else if (!ft_strncmp(&line[0], "NO ", 3))
	{
		d->i.nwall = ft_strdup(&line[3]);
		deny_struct_n(d->i.nwall);
		d->flag.no = 1;
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
		d->end_flag = 1;
	while (beg < sufixp)
	{
		if (!ft_isprint(path[beg]) || path[beg] == ' ')
			d->end_flag = 1;
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
