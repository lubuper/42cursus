/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:30:32 by lde-sous          #+#    #+#             */
/*   Updated: 2023/10/09 20:12:17 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	rgb_to_int(int red, int green, int blue)
{
	int	colour;

	colour = (red << 16) + (green << 8) + blue;
	return (colour);
}

int	max_min(t_data *d, char *nbr)
{
	if ((ft_atoi(nbr) < 0 || ft_atoi(nbr) > 255) || d->c.fc_flag > 2)
	{
		free(nbr);
		return (0);
	}
	if (d->c.fc_flag == 0)
	{
		d->c.f_r = ft_atoi(nbr);
		d->c.fc_flag++;
	}
	else if (d->c.fc_flag == 1)
	{
		d->c.f_g = ft_atoi(nbr);
		d->c.fc_flag++;
	}
	else if (d->c.fc_flag == 2)
	{
		d->c.f_b = ft_atoi(nbr);
		d->c.fc_flag++;
	}
	return (1);
}

int	inspect_line(t_data *d, char *line)
{
	int		start;
	int		end;
	char	*nbr;
	int		i;

	end = 0;
	while (end < (int)ft_strlen(line))
	{
		start = end;
		while (line[end] && line[end] != ',')
		{
			if (!ft_isdigit(line[end++]))
				return (0);
		}
		i = 0;
		nbr = malloc(sizeof(char) * (end - start + 1));
		while (start < end)
			nbr[i++] = line[start++];
		nbr[i] = '\0';
		if (!max_min(d, nbr))
			return (0);
		free(nbr);
		end++;
	}
	return (1);
}

void	verify_values(t_data *d)
{
	char	*temp;

	temp = ft_strtrim(d->c.floor_c, " ");
	d->c.fc_flag = 0;
	if (!inspect_line(d, temp))
	{
		free(temp);
		printf("Error!\nPlease set values between 0 - 255!\n");
		frees(d);
		exit(1);
	}
	d->c.fl_color = rgb_to_int(d->c.f_r, d->c.f_g, d->c.f_b);
	free(temp);
	temp = ft_strtrim(d->c.ceil_c, " ");
	d->c.fc_flag = 0;
	if (!inspect_line(d, temp))
	{
		free(temp);
		printf("Error!\nPlease set values between 0 - 255!\n");
		frees(d);
		exit(1);
	}
	d->c.ce_color = rgb_to_int(d->c.f_r, d->c.f_g, d->c.f_b);
	free(temp);
}

void	draw_floor_ceil(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i <= HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_to_scr(d, j, i, d->c.ce_color);
			j++;
		}
		i++;
	}
	while (i <= HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_to_scr(d, j, i, d->c.fl_color);
			j++;
		}
		i++;
	}
}
