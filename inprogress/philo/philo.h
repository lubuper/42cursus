/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/05/17 16:22:27 by lde-sous         ###   ########.fr       */
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

typedef struct s_philo
{
	int		no;
	pthread_t	thread_no;
	pthread_t	thread_term;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	long long	last_meal;
	t_args		*t_args;

}			t_philo

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

int	valid_args(int ac, char **av);
void	init_vars(int ac, char **av, t_p);

#endif
