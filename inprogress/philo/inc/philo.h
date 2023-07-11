/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/11 12:30:52 by lde-sous         ###   ########.fr       */
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
	

}			t_philo;

typedef struct s_args
{
	int				nb_phils;
	int				t_until_death;
	int				t_of_meal;
	int				t_sleep;
	int				meals;
	int				forks;
	long int		t_start;

	pthread_mutex_t	write_mutex;

}			t_args;

typedef struct s_phil
{
	int				no;
	pthread_t		thread_no;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	long long		last_meal;
	t_args			arg;
}					t_phil;

//  time_fun.c
long int	get_time(void);
void	ft_usleep(long int miliseconds);

// philo_utils.c
int		valid_args(int ac, char **av, t_phil *p);
void	get_args(int ac, char **av, t_phil *p);
//void	init_vars(int ac, char **av, t_phil *p);
void	free_vars(t_phil *p);
int		ph_atoi(char *str);
void	print_changes(char *str, t_phil *p);

// philo.c
void	*job(void *voidling);
void	thread_maker(t_phil *p);
int		main(int ac, char **av);

#endif
