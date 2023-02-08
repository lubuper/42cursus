/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:12 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/08 20:47:37 by lde-sous         ###   ########.fr       */
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

void	send_msg(pid_t process_id, char *str)
{
	int				i;
	int				bit;
	int				len;
	unsigned char	c;

	i = 0;
	len = ft_strlen(str);
	str[len] = '\0';
	while (i <= len)
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

void	reply(int signal, siginfo_t *info, void *nothing)
{
	(void)info;
	(void)nothing;
	if (signal == SIGUSR1)
		ft_printf("The server has received the message! Exiting now...\n");
}

int	main(int ac, char **av)
{
	int					i;
	pid_t					process_id;
	struct sigaction	the_reply;

	i = 0;
	if (ok(ac, av) == 1)
	{
		process_id = ft_atoi(av[1]);
		the_reply.sa_sigaction = &reply;
		the_reply.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &the_reply, NULL);
		sigaction(SIGUSR2, &the_reply, NULL);
		send_msg(process_id, av[2]);
	}
	return (0);
}
