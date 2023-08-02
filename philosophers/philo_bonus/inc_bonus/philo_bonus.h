/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:13 by lde-sous          #+#    #+#             */
/*   Updated: 2023/08/02 18:17:04 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdatomic.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>

# define FORKMSG "\e[0;37mhas taken a fork\e[0m\n"
# define EATMSG "\e[0;33mis eating\e[0m\n"
# define SLEEPMSG "\e[0;34mis sleeping\e[0m\n"
# define THINKMSG "\e[0;35mis thinking\e[0m\n"
# define DEADMSG "\e[0;31mdied\e[0m\n"
# define ENDMSG "\e[0;32mhas finished the meals\e[0m\n"

typedef struct s_args
{
	int					finished_meals;
	int					nb_phils;
	int					t_until_death;
	int					t_of_meal;
	int					t_sleep;
	int					meals;
	atomic_int			is_dead;
	long int			t_start;
	sem_t				*verif;
	sem_t				*write_sem;
	sem_t				*forks;
	pthread_t			watcher;
	int					*pid;
}						t_args;

typedef struct s_phil
{
	int					no;
	_Atomic long int	last_meal;
	t_args				*arg;
}						t_phil;

typedef struct s_data
{
	t_phil	ph;
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
void		put_down_forks(t_data *p);
void		lets_eat(t_data *p);

// death.c
void		*check_death(void *data);

#endif
