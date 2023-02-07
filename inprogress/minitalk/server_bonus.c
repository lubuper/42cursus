/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:01 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/07 16:08:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_msg(int signal)
{
	static int				i = 0;
	static unsigned char	bin = 0;
	unsigned char			bit;

	bit = (signal == SIGUSR1);
	bin |= (bit << i);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(bin, 1);
		if (bin == 0)
			kill(info->si_pid, SIGUSR1);
		i = 0;
		bin = 0;
	}
}

void	send

int	main(void)
{
	int					p;
	struct sigaction	the_sig;

	p = getpid();
	ft_printf("lde-sous 's server ON\nPID: %d\n", p);
	the_sig.sa_handler = &receive_msg;
	the_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &the_sig, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &the_sig, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
