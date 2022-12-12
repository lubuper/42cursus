/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:21 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/12 18:34:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	ft_check_sp(char to_check)
{
	char	*format;
	int	i;

	i = 0;
	format = "csidxXup%";
	while (format[i])
	{
		if (to_check = format[i])
			return (format[i]);
		i++;
	}
	return (0);
}
