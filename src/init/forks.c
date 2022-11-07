/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:21:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/07 12:15:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	init_forks_as_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_t	*mutex;
	mutex = malloc(sizeof(pthread_mutex_t));
	philo->r_fork = malloc(sizeof(t_fork));//NOT FREED!
	// philo->l_fork = malloc(sizeof(t_fork));
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf("fail");
		return (EXIT_FAILURE);
	}
	philo->r_fork->state = FREE;
	philo->r_fork->mutex = mutex;
	// pthread_mutex_unlock(philo->r_fork->mutex);
	// if (pthread_mutex_lock(philo->r_fork->mutex) == 0)
	// 	philo->r_fork->state = TAKEN;
	// else
	// 	return (EXIT_FAILURE);

	if (pthread_mutex_unlock(philo->r_fork->mutex) == 0)
	{
		philo->r_fork->state = FREE;
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}