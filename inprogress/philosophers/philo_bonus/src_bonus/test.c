/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:03:23 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/31 16:15:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/philo_bonus.h"

void	processes_start(t_data *p)
{
	int		i;
	int		status;
	
	i = 0;
	while (i < p->arg.nb_phils)
	{
		if ((p->ph[i].pid = fork()) < 0)
		{
	    	perror("fork");
	    	abort();
		}
		else if (p->ph[i].pid == 0)
		{
	    	job(p);
	    	exit(0);
		}
	}

	i = 0;
	while (i < p->arg.nb_phils)
	{
		p->ph[i].pid = wait(&status);
		printf("Child with PID %ld exited with status 0x%x.\n", (long)p->ph[i].pid, status);
		i++;
	}
}
