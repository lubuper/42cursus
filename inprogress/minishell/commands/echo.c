/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:57:28 by alexandre         #+#    #+#             */
/*   Updated: 2023/05/18 21:19:49 by alexfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	prints the string after echo command to the terminal
	> format: "echo <string>"
	> status: working
*/
void	echo(t_attr att)
{
	int		i;

	i = 1;
	if (att.nb_tokens == 1)
		ft_putchar_fd('\n', 1);
	else if (!strcmp(att.s_arr[0], "echo") && !strcmp(att.s_arr[1], "-n"))
	{	
		i = 2;
		while(i < att.nb_tokens)
		{
			ft_putstr_fd(att.s_arr[i], 1);
			if (att.s_arr[i + 1])
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (!strcmp(att.s_arr[0], "echo"))
    {
		while(i < att.nb_tokens)
		{
			ft_putstr_fd(att.s_arr[i], 1);
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putchar_fd('\n', 1);
	}
}