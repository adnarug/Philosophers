/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:31:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/06 16:56:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*Initialization is always done per thread = per philo*/
t_philo	*init_philos(t_philo *philos, t_ph_meta *philo_data)
{
	int	i;
	int counter;
	
	i = 1;
	counter = 0;
	philos =  malloc(sizeof(t_philo) * philo_data->num_philo); //maybe we allocate only the pointers here 
	if (philos == NULL)
		return (NULL);
	philo_data->died= FALSE;
	while (counter < philo_data->num_philo)
	{
		philos[counter].meta = philo_data;
		philos[counter].is_dead = FALSE;
		philos[counter].num_meals = 0;
		philos[counter].id = i;
		//printf("Philosopher id: %d\n", philos[3].id)
		if (init_forks_as_mutex(&philos[counter]) == EXIT_FAILURE)
			return (NULL);
		if (philos[counter].id != 0)
			philos[counter].l_fork =  philos[counter - 1].r_fork;
		if (philos[counter].id != philos->meta->num_philo)
			philos[0].l_fork = philos[counter].r_fork;
		philos[counter].start_time = get_time();
		// if (philos[counter].id == 3 && philos[counter].r_fork->state == FREE && philos[counter].l_fork->state == FREE)
		// 	printf("cheeky check\n");
		counter++;
		i++;
	}
	// i = 0;
	// while (i < philos->meta->num_philo)
	// {
	// 	pthread_join(philos[counter].threads, NULL);
	// 	i++;
	// }
	return (philos);
}