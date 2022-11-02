/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:02:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/02 18:10:07 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*routine (void *philos)
{
	void	*result;
	t_philo	*phil;
	int		i;

	i = 0;
	phil = (t_philo*)philos;
	result = NULL;
	eating(phil);
	return result;
}

int	create_threads(t_ph_meta *philo_data, t_philo *philos)
{
	int		counter;

	counter = 0;
	philos->meta = philo_data;
	while (counter < philo_data -> num_philo)
	{
		philos[counter].threads = malloc(sizeof(pthread_t));
		if (philos[counter].threads == NULL)
			return (EXIT_FAILURE);
		printf("Cheeky check\n");
		if (pthread_create(philos[counter].threads, NULL, &routine, philos) != 0)
			return (EXIT_FAILURE);
		// philo->time_die++;
		counter++;
	// while (i < philo->num_philo)
	// {
	// 	if (pthread_join(philos->threads[i], NULL) != 0)
	// 				return (EXIT_FAILURE);
	// 	i++;
	}
	return (EXIT_SUCCESS);
}