/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:13:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/07 12:09:55 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>

long int	get_time(void)
{
	struct timeval	ftime;
	long int		time;

	time = 0;
	if (gettimeofday(&ftime, NULL))
		return (-1);
	time = (ftime.tv_sec * 1000) + (ftime.tv_usec / 1000);
	return (time); // in miliseconds

}

void	ft_usleep(long int miliseconds)
{
	long int	start;

	start = 0;
	start = get_time();
	while (get_time() - start < miliseconds)
		usleep(miliseconds / 10);
}


void	*func()
{
	int		i;
	
	i = 0;
	while (i < 10)
	{
		printf("count = %d\n", i);
		ft_usleep(100);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	//int		i;
	pthread_t	newthread;
	
	pthread_create(&newthread, NULL, func, NULL);
	pthread_join(newthread, NULL);
	return (0);
}
