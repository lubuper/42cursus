/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:50:44 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/11 16:45:06 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	positive_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	if (str[i] == '+')
			i++;
	while (str[i] && (str[i] < '0') || (str[i] > '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	*function(void)
{
	pthread_mutex_lock(&mutex);

	pthread_mutex_unlock(&mutex);
}



int	main(int ac, char *av)
{
	pthread_t		thread[positive_atoi(ac[2])];
	pthread_t		thread2;
	pthread_mutex_t mutex;

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
	return (0);
}
