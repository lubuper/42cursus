/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/01 13:06:59 by lde-sous         ###   ########.fr       */
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

# define FORKMSG "\e[0;37mhas taken a fork\e[0m\n"
# define EATMSG "\e[0;33mis eating\e[0m\n"
# define SLEEPMSG "\e[0;34mis sleeping\e[0m\n"
# define THINKMSG "\e[0;35mis thinking\e[0m\n"
# define DEADMSG "\e[0;31mdied\e[0m\n"
# define ENDMSG "\e[0;32mhas finished the meals\e[0m\n"

typedef struct s_args
{
	int				nb_phils;
	int				t_until_death;
	int				t_of_meal;
	int				t_sleep;
	int				meals;
	int				is_dead;
	long int		t_start;
	pthread_mutex_t	last_mutex;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	end_mutex;
	pthread_t		death;
}					t_args;

typedef struct s_phil
{
	int				no;
	pthread_t		thread_no;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	long int		last_meal;
	t_args			*arg;
}					t_phil;

typedef struct s_data
{
	t_phil	*ph;
	t_args	arg;
}			t_data;

//  time_fun.c
long int	get_time(void);
void		ft_usleep(long int miliseconds);

// philo_utils.c
int			valid_args(int ac, char **av, t_data *p);
void		get_args(int ac, char **av, t_data *p);
void		free_vars(t_data *p);
int			ph_atoi(char *str);
void		print_changes(char *str, t_phil *p);
void		philo_args(t_data *p);

// philo.c
void		*job(void *voidling);
void		thread_maker(t_data *p);
int			main(int ac, char **av);
void		printmsg(char *str, t_phil *pointer);
int			get_l_fork(t_phil *pointer);
int			get_r_fork(t_phil *pointer);
void		put_down_forks(t_phil *pointer);
void		lets_eat(t_phil *pointer);

// death.c
void		*check_death(void *ph);
void		is_dead(t_phil *ph);

#endif
