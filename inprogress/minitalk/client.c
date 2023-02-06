/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:45:05 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/06 15:23:24 by lde-sous         ###   ########.fr       */
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

int	ok(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Please, check your input arguments\n");
		return (0);
	}
	else if (*argv[2] == 0)
	{
		ft_printf("Error: MESSAGE field empty\n");
		return (0);
	}
	else if (checkpid(argv[1]) == 0)
	{
		ft_printf("Error: PID should contain only numbers\n");
		return (0);
	}
	else
		return (1);
}

void	send_msg(int process_id, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		usleep(47);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		process_id;
	char	*to_send;

	i = 0;
	if (ok(ac, av) == 1)
	{
		process_id = ft_atoi(av[1]);
		to_send = ft_strdup(av[2]);
		while (to_send[i])
		{
			send_msg(process_id, to_send[i]);
			i++;
		}
		free(to_send);
		send_msg(process_id, '\n');
	}
	return (0);
}
