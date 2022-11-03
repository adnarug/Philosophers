/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:02:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/03 16:32:13 by pguranda         ###   ########.fr       */
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
	int		i;

	counter = 0;
	i = 0;
	while (i <= philo_data->num_philo)
	{
		philos[i].id = i;
		init_forks_as_mutex(&philos[i]);
		if (i != 0)
			philos[i].l_fork = philos[i - 1].r_fork;
		i++;
	}
	i = 0;
	while (counter < philo_data -> num_philo)
	{
		philos[counter].meta = philo_data;
		philos[counter].threads = malloc(sizeof(pthread_t));
		if (philos[counter].threads == NULL)
			return (EXIT_FAILURE);
		if (pthread_create(philos[counter].threads, NULL, &routine, &philos[counter]) != 0)
			return (EXIT_FAILURE);
		// while (i < philo_data->num_philo)
		// {
			if (pthread_join(*(philos[counter].threads), NULL) != 0)
					return (EXIT_FAILURE);
		// 	i++;
		// }
		// philo->time_die++;
		counter++;
	}
	return (EXIT_SUCCESS);
}