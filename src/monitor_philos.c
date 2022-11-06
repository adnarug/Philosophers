/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:32:15 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 13:43:29 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void monitor_philos(t_philo *philo)
{
	while (philo->is_dead != TRUE)
	{
		if (is_dead(philo) == 1)
			philo->meta->died = TRUE;
		return ;
	}
}

int is_dead(t_philo *philo)
{
	int	time_elapsed;
	int	curr_time;

	curr_time = get_time() - philo->start_time;
	time_elapsed = curr_time - philo->last_start_eat;
	if (time_elapsed >= philo->meta->time_die)
	{
		printf("%d %d has died\n", get_time() - philo->start_time, philo->id);
		philo->is_dead = TRUE;
		return (1);
	}
	return 0;
}