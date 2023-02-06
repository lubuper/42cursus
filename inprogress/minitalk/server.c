/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:45:15 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/06 15:44:46 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_msg(int signal)
{
	static int				bit;
	static unsigned char	c;

	bit = 0;
	c = 0;
	if (signal == SIGUSR1)
		c = c | (1 << bit);
	else if (signal == SIGUSR2)
		
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int					p;
	struct sigaction	the_sig;

	the_sig.sa_handler = &receive_msg;
	the_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &the_sig, NULL);
	sigaction(SIGUSR2, &the_sig, NULL);
	p = getpid();
	ft_printf("lde-sous 's server ON\nPID: %d\n", p);
	while (1)
		pause();
	return (0);
}
