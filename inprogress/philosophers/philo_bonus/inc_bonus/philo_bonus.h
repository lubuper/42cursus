/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/07/31 19:00:28 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>

# define FORKMSG "has taken a fork\n"
# define EATMSG "is eating\n"
# define SLEEPMSG "is sleeping\n"
# define THINKMSG "is thinking\n"
# define DEADMSG "died\n"
# define ENDMSG "has finished the meals\n"

typedef struct s_args
{
	int			nb_phils;
	int			t_until_death;
	int			t_of_meal;
	int			t_sleep;
	int			meals;
	int			is_dead;
	long int	t_start;
	sem_t		death;
	sem_t		write_sem;
	sem_t		final_sem;
	sem_t		forks;
	pthread_t	watcher;
}				t_args;

typedef struct s_phil
{
	int			no;
	pid_t		pid;
	long int	last_meal;
	t_args		*arg;
}				t_phil;

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
void		print_changes(char *str, t_data *p);
void		philo_args(t_data *p);

// philo.c
void		job(t_data	*p, int p_nb);
void		processes_start(t_data *p);
int			main(int ac, char **av);
void		printmsg(char *str, t_data *p);
int			get_l_fork(t_data *p);
int			get_r_fork(t_data *p);
void		put_down_forks(t_data *p);
void		lets_eat(t_data *p);

// death.c
void		*check_death(void *data);

#endif
