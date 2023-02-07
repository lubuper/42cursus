/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/07 16:09:51 by lde-sous         ###   ########.fr       */
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
	int				length;

	i = 0;
	length = ft_strlen(str);
	while (i <= length)
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
	str[i] = 0;
}

void	reply(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Server Received the message! Exiting now...");
}

int	main(int ac, char **av)
{
	int					i;
	int					process_id;
	struct sigaction	the_reply;

	i = 0;
	if (ok(ac, av) == 1)
	{
		process_id = ft_atoi(av[1]);
		send_msg(process_id, av[2]);
		the_reply.sa_handler = &reply;
		the_reply.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &the_reply, NULL) == -1)
			exit(1);
		if (sigaction(SIGUSR2, &the_reply, NULL) == -1)
			exit(1);
		while (1)
			pause();
	}
	return (0);
}
