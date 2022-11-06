/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:49:40 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 15:56:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int thinking(t_philo *philo)
{
	// if (philo->state == EATING)
	// 	philo->state = SLEEPING;
	if (philo->is_dead == TRUE)
		return(EXIT_FAILURE);
	// if (pthread_mutex_trylock(philo->r_fork->mutex) != 0 || pthread_mutex_trylock(philo->l_fork->mutex))
		printf("%d %d is thinking\n", get_time() - philo->start_time, philo->id);
	return (EXIT_SUCCESS);
}