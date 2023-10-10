/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:05:48 by lubu              #+#    #+#             */
/*   Updated: 2023/10/09 19:32:41 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

	d->lns = count_lines(av) - 6;
	handle_file_aux(d);
	d->map = malloc(sizeof(char *) * (d->lns + 1));
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, true);
		if (!line)
		{
			free(line);
			break ;
		}
		line2 = ft_strtrim(line, " ");
		free(line);
		if (line2[0] != '\n' && line2[0] != '\0')
			treat_line(d, line2);
		free(line2);
		line = 0;
	}
	close(fd);
}

void	treat_line(t_data *d, char *line)
{
	if ((int)ft_strlen(line) > 3)
	{
		if (line[0] == 'F' || line[0] == 'C' || line[0] == 'N' || line[0] == 'S'
			|| line[0] == 'W' || line[0] == 'E')
		{
			verify_line_data(d, line);
			d->flag_six++;
		}
		else if (d->flag_six == 6 && (line[0] == ' ' || line[0] == '1'))
			verify_map_line(d, line);
		else
		{
			printf("Error\nInvalid line!\n");
			free(line);
			frees(d);
		}
	}
	else
	{
		printf("Error\nInvalid line!\n");
		free(line);
		frees(d);
	}
}

void	verify_line_data(t_data *d, char *line)
{
	int		i;

	i = 0;
	if (!strncmp(&line[i], "F ", 2) && !d->flag.f && colornbr(&line[i + 2]))
		color_to_var(d, line);
	else if (!strncmp(&line[i], "C ", 2) && !d->flag.c
		&& colornbr(&line[i + 2]))
		color_to_var(d, line);
	else if (!strncmp(&line[i], "EA ", 3) && !d->flag.ea)
		path_to_var(d, line);
	else if (!strncmp(&line[i], "WE ", 3) && !d->flag.we)
		path_to_var(d, line);
	else if (!strncmp(&line[i], "SO ", 3) && !d->flag.so)
		path_to_var(d, line);
	else if (!strncmp(&line[i], "NO ", 3) && !d->flag.no)
		path_to_var(d, line);
	else
	{
		printf("Error\nInvalid line!\n");
		free(line);
		frees(d);
	}
}

void	verify_map_line(t_data *d, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	while (line[i] && line[i] != '\n')
	{
		if (d->flag_pos == 0 && (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
		{
			d->flag_pos = 1;
			d->px = TS * i + TS / 2;
			d->py = TS * d->current_line + TS / 2;
			d->d = line[i];
		}
		else if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			d->end_flag = true;
		}
		i++;
	}
	d->map[d->current_line] = malloc(sizeof(char) * len);
	ft_strlcpy(d->map[d->current_line], line, len);
	d->current_line++;
}
