/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:02:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/04 17:04:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*Even numbered threads start with a delay to avoid deadlock*/
static void	*routine (void *philos)
{

	t_philo	*phil;
	int		i;

	i = 0;
	phil = philos;
	// phil->id = 1;
	// printf("	id of the philo:%d\n", phil->id);
	if (phil->id % 2 == 0)
		my_sleep(phil->meta->time_eat / 2);
	take_fork(phil);
	eat(phil);
	return (NULL);
}

int	create_thread(t_philo *philos)
{
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	// printf("id of the philo before:%d\n", philos->id);
	if (pthread_create(&philos->threads, NULL, &routine, (void *)philos) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}