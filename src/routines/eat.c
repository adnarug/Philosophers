/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:54:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/07 12:54:17 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int eat(t_philo *philo)
{
	if (philo->is_dead == TRUE)
		return(EXIT_FAILURE);

	if (philo->state == TOOK_FORKS)
	{
		philo->last_start_eat = get_time() - philo->start_time;
		printf("%d %d is eating\n", get_time() - philo->start_time, philo->id);
		my_sleep(philo->meta->time_eat);
		put_fork(philo);
		philo->state = IDLE;
		philo->num_meals++;
	}
	return (EXIT_SUCCESS);
}