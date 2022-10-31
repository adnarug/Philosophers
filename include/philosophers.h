/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:21:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 13:44:26 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>//to be deleted
#include <string.h>//to be deleted
#include <pthread.h>

typedef enum e_boolean
{
	TRUE = 1,
	FALSE =	0
}	t_bool;


typedef struct s_fork
{
	int	id;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_ph_meta 
{
	int					num_philo;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					num_meals;
	t_bool				with_option;
	t_fork				forks;
	pthread_mutex_t		mutex;
} t_ph_meta;

typedef struct s_philo
{
	int	id;
	typedef struct s_philo;
} t_philo


int		check_argv(t_ph	*philo_data, char **argv);
void	print_struct(t_ph *philo);
int		create_threads(t_ph *philo, pthread_t *philosophers);

#endif