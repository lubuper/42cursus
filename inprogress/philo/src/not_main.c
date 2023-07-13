/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:13:51 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/10 11:32:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

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

pthread_mutex_t	lock;
int		i;

void	*func()
{
	while (i < 10000)
	{
		pthread_mutex_lock(&lock);
		if (i == 10000)
		{
			pthread_mutex_unlock(&lock);
			break ;
		}
		i++;
		printf("i = %d\n", i);
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	newthread[4];
	int		j;

	j = 0;
	pthread_mutex_init(&lock, NULL);
	while (j < 4)
	{
		printf("tread %d started\n", j);
		pthread_create(&newthread[j], NULL, func, NULL);
		j++;
	}
	j = 0;
	while (j < 4)
	{
		pthread_join(newthread[j], NULL);
		printf("tread %d finished\n", j);
		j++;
	}
	pthread_mutex_destroy(&lock);
	printf("count = %d\n", i);
	return (0);
}
