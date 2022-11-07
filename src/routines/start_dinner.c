/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:43:20 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/07 16:05:58 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	start_dinner(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->meta->num_philo)
	{
		if (pthread_create(&philo[i].threads, NULL, &routine, (void *)&philo[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	monitor_philos(philo);
	while (i < philo->meta->num_philo)
	{
		if (pthread_join(philo[i].threads, NULL) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}