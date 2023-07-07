/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/07 11:15:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*function(void)
{
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
}

void	thread_maker(char **av, t_phil t_phil)
{
	int		i;
	pthread_t	thread[t_phil->t_args.num];
	pthread_mutex_t mutex;
	
	i = 0;
	while (i < atoi(av[1]))
	{
		pthread_mutex_init(&mutex, NULL);
		if (pthread_create(&thread1, NULL, &function, NULL) != 0)
			return (1);
		if (pthread_create(&thread2, NULL, &function, NULL) != 0)
			return (2);
		if (pthread_join(thread1, NULL) != 0)
			return (3);
		if (pthread_join(thread2, NULL) != 0)
			return (4);
			pthread_mutex_destroy(&mutex);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (valid_args(ac, av) == 0)
		return (0);
	thread_maker(av, &p);
	return (0);
}
