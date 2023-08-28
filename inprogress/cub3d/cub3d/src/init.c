/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:42:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/16 17:18:00 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struct(t_data	*d, int ac, char **av)
{
	ft_memset(d, 0, sizeof(*d));
	d->d = 'N';
	valid_file(ac, av);
	handle_file(d, av);
	treat_map(d);
	verify_values(d);
}
