/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:35:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 15:50:47 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int sleeping(t_philo *philo)
{
	// if (philo->state == EATING)
	// 	philo->state = SLEEPING;
	if (philo->is_dead == TRUE)
		return(EXIT_FAILURE);
	printf("%d %d is sleeping\n", get_time() - philo->start_time, philo->id);
	my_sleep(philo->meta->time_sleep);
	return (EXIT_SUCCESS);
}