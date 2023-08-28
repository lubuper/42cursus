/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:21:11 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/28 14:09:56 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	gnllen(int fd)
{
	char	*temp;
	int		len;

	temp = 0;
	len = 0;
	temp = get_next_line(fd, 1);
	if (temp == 0)
		return (0);
	len = ft_strlen(temp);
	free (temp);
	return (len);
}
