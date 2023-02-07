/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/07 14:07:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	checkpid(char *strpid)
{
	int	i;

	i = 0;
	while (strpid[i])
	{
		if (ft_isdigit(strpid[i]) == 1)
				i++;
		else
			return (0);
	}
	return (1);
}

int	ok(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Error: Please, check your input arguments\n");
		return (0);
	}
	else if (av[2] == 0)
	{
		ft_printf("Error: MESSAGE field empty\n");
		return (0);
	}
	else if (checkpid(av[1]) == 0)
	{
		ft_printf("Error: PID should contain only numbers\n");
		return (0);
	}
	else
		return (1);
}

void	send_msg(int process_id, char *str)
{
	int				i;
	int				bit;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		bit = 8;
		c = (unsigned char)str[i];
		while (bit > 0)
		{
			if (c & 0b00000001)
				kill(process_id, SIGUSR1);
			else
				kill(process_id, SIGUSR2);
			c = c >> 1;
			bit--;
			usleep(200);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	process_id;

	i = 0;
	if (ok(ac, av) == 1)
	{
		process_id = ft_atoi(av[1]);
		send_msg(process_id, av[2]);
	}
	return (0);
}
