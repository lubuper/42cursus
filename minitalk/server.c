/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:45:15 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/07 12:17:09 by lde-sous         ###   ########.fr       */
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
		i = 0;
		bin = 0;
	}
}

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
