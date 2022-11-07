/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:31:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/07 12:54:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int take_fork(t_philo	*philo)
{
	int		i;

	i = 0;
	if (philo->is_dead == TRUE)
		return(EXIT_FAILURE);
	if (pthread_mutex_lock(philo->r_fork->mutex) == 0 && pthread_mutex_lock(philo->l_fork->mutex) == 0)
	{	
		philo->r_fork->state = TAKEN;
		printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
		philo->l_fork->state = TAKEN;
		printf("%d %d has taken a fork\n", get_time() - philo->start_time, philo->id);
	}
	philo->state = TOOK_FORKS;
	return (EXIT_SUCCESS);
}

int put_fork(t_philo	*philo)
{
	int		i;

	i = 0;

	if (philo->r_fork->state == TAKEN && philo->l_fork->state == TAKEN)
	{
		pthread_mutex_unlock(philo->r_fork->mutex);
		philo->r_fork->state = FREE;
		// printf("%d %d has put down a fork\n", get_time() - philo->start_time, philo->id);
		pthread_mutex_unlock(philo->l_fork->mutex);
		// printf("%d %d has put down a fork\n", get_time() - philo->start_time, philo->id);
		philo->l_fork->state = FREE;
	}
	return (EXIT_SUCCESS);
}