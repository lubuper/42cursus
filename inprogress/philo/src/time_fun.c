/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:08:31 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/10 19:06:24 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

/*int	main(void)
{
	uint64_t	start_t;
	uint64_t	now;
	int	i;

	i = 0;
	start_t = get_time();
	usleep(100000); //microseconds
	now = get_time();
	printf("time passed sleeping = %ldms\n", now - start_t);
	printf("go again\n");
	start_t = get_time();
	ft_usleep(100); //miliseconds
	now = get_time();
	printf("time passed sleeping = %ldms\n", now - start_t);
	return (0);
}*/
