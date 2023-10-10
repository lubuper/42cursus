/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:05:48 by lubu              #+#    #+#             */
/*   Updated: 2023/10/09 20:01:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	count_lines(char **av)
{
	int		fd;
	int		result;
	char	*line;

	result = 0;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, true);
		if (!line)
		{
			free(line);
			break ;
		}
		if (line[0] != '\n' && line[0] != '\0')
			result++;
		free(line);
		line = 0;
	}
	close(fd);
	return (result);
}

void	handle_file(t_data *d, char **av)
{
	int		fd;
	char	*line;
	char	*line2;

	line2 = 0;
	d->lns = count_lines(av) - 6;
	handle_file_aux(d);
	d->map = malloc(sizeof(char *) * d->lns);
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, true);
		if (!line)
		{
			free(line);
			break ;
		}
		if (line[0] != '\n' && line[0] != '\0')
			treat_line(d, line, line2);
		free(line);
		line = 0;
	}
	close(fd);
}

void	treat_line(t_data *d, char *line, char *line2)
{
	if (d->flag_six < 6)
	{
		line2 = ft_strtrim(line, " ");
		if (line2[0] && line2[0] != '\n')
		{
			if ((int)ft_strlen(line2) > 3)
			{
				if (line2[0] == 'F' || line2[0] == 'C' || line2[0] == 'N'
					|| line2[0] == 'S' || line2[0] == 'W' || line2[0] == 'E')
				{
					verify_line_data(d, line, line2);
					d->flag_six++;
					free(line2);
				}
				else
					iv_line_err(d, line, line2);
			}
			else
				iv_line_err(d, line, line2);
		}
	}
	else if (d->flag_six == 6 && (line[0] == ' ' || line[0] == '1'))
		verify_map_line(d, line);
	else
		iv_line_err(d, line, line2);
}

void	verify_line_data(t_data *d, char *line, char *line2)
{
	int		i;

	i = 0;
	if (!strncmp(&line2[i], "F ", 2) && !d->flag.f && colornbr(&line2[i + 2]))
		color_to_var(d, line2);
	else if (!strncmp(&line2[i], "C ", 2) && !d->flag.c
		&& colornbr(&line2[i + 2]))
		color_to_var(d, line2);
	else if (!strncmp(&line2[i], "EA ", 3) && !d->flag.ea)
		path_to_var(d, line2);
	else if (!strncmp(&line2[i], "WE ", 3) && !d->flag.we)
		path_to_var(d, line2);
	else if (!strncmp(&line2[i], "SO ", 3) && !d->flag.so)
		path_to_var(d, line2);
	else if (!strncmp(&line2[i], "NO ", 3) && !d->flag.no)
		path_to_var(d, line2);
	else
	{
		if (line)
			free(line);
		free(line2);
		printf("Error\nInvalid line!\n");
		frees(d);
	}
}

void	verify_map_line(t_data *d, char *l)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(l);
	while (l[i] && l[i] != '\n')
	{
		if (d->flag_pos == 0 && (l[i] == 'N' || l[i] == 'S'
				|| l[i] == 'E' || l[i] == 'W'))
		{
			d->flag_pos = 1;
			d->px = TS * i + TS / 2;
			d->py = TS * d->current_line + TS / 2;
			d->d = l[i];
		}
		else if (l[i] != '1' && l[i] != '0' && l[i] != ' ' && l[i] != 'D')
		{
			d->end_flag = true;
		}
		i++;
	}
	d->map[d->current_line] = malloc(sizeof(char) * len);
	ft_strlcpy(d->map[d->current_line], l, len);
	d->current_line++;
}
