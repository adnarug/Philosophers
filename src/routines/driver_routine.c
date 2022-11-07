/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   driver_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:27:47 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/07 16:05:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

/*Even numbered threads start with a delay to avoid deadlock*/
void	*routine (void *philos)
{

	t_philo	*phil;
	int		i;

	i = 0;
	phil = philos;
	// phil->id = 1;
	if (phil->id % 2 == 0)
		my_sleep(phil->meta->time_eat / 2);
	// printf("\n	id of the philo:%d\n", phil->id)
	while (phil->meta->died == FALSE && phil->is_dead == FALSE)
	{
		take_fork(phil);
		eat(phil);
		sleeping(phil);
		thinking(phil);
	}
	return (NULL);
}