/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 16:15:56 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>//to be deleted
#include <string.h>//to be deleted
#include <pthread.h>
#include <sys/time.h>

typedef enum e_boolean
{
	TRUE = 1,
	FALSE =	0
}	t_bool;

typedef enum e_philo_state
{
	READY_TO_EAT = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	IS_DEAD = 4
}	t_state;

typedef enum e_fork_state
{
	TAKEN = 1,
	FREE = 0
}	t_fork_state;


typedef struct s_fork
{
	t_fork_state	state;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_ph_meta 
{
	int					num_philo;
	int					time_die;
	int					death_timer; //since the beginning of the meal
	int					time_eat;
	int					time_sleep;
	int					meals_limit;
	t_bool				died;
	t_bool				with_option;
	t_fork				forks;
	pthread_mutex_t		*mutex;
} t_ph_meta;

typedef struct s_philo
{
	pthread_t			threads;
	int					id;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_state				state;
	int					start_time;
	int					curr_time;
	int					time_start_eat;
	int					num_meals;
	int					time_to_sleep;
	int					last_start_eat;
	t_bool				is_dead;
	t_ph_meta			*meta;
} t_philo;


int				check_argv(t_ph_meta	*philo_data, char **argv);
void			print_struct(t_ph_meta *philo);
int				create_thread(t_philo *philos);
int				start_time();
unsigned long	end_time();
void			mili_sleep(int i);
int				take_fork(t_philo	*philo);
int				get_time(void);
int				init_forks_as_mutex(t_philo *philo);
void			my_sleep(int ms);
int				put_fork(t_philo	*philo);
int				eat(t_philo *philo);
int				sleeping(t_philo *philo);
int				thinking(t_philo *philo);
void			*routine (void *philos);
t_philo			*init_philos(t_philo *philos, t_ph_meta *philo_data);
int				start_dinner(t_philo *philo);
void			monitor_philos(t_philo *philo);
int			is_dead(t_philo *philo);
#endif