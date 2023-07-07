/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/07 11:52:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef struct s_philo
{
	int		no;
	pthread_t	th_no;
	pthread_t	th_term;
	pthread_mutex_t	left_f;
	pthread_mutex_t	*right_f;
	long long	last_meal;
	//t_args		*t_args;

}			t_philo;

typedef struct s_args
{
	int		philos;
	int		ttdie;
	int		tteat;
	int		ttsleep;
	int		meals;
	int		forks;

}			t_args;

typedef struct s_p
{
	t_philo		*ph;
	t_args		a;
}			t_p;

//  time_fun.c
long int	get_time(void);
void	ft_usleep(long int miliseconds);

int		valid_args(int ac, char **av);
void	init_vars(int ac, char **av, t_p);

#endif
